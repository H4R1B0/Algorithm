#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 20+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, result;
int map[MAX][MAX];
bool Select[MAX * MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> Empty;

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;
	int cnt = 0;
	bool isPossible = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) isPossible = false;
			else if (map[nx][ny] == 1) continue;
			else if (map[nx][ny] == 2) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
	if (!isPossible) return 0;
	return cnt;
}

int Calculate() {
	int cnt = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2 && !visit[i][j]) {
				cnt += bfs(i, j);
			}
		}
	}
	return cnt;
}

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		result = max(result, Calculate());
		return;
	}

	for (int i = idx;i < Empty.size();i++) {
		if (map[Empty[i].first][Empty[i].second] == 1)
			continue;

		map[Empty[i].first][Empty[i].second] = 1;
		dfs(i, cnt + 1);
		map[Empty[i].first][Empty[i].second] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				Empty.push_back({ i,j });
		}
	}

	dfs(0, 0);
	cout << result;
}