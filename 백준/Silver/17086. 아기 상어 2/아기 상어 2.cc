#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, result;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (map[x][y] == 1) {
			dist[a][b] = cnt;
			result = max(result, cnt);
			return;
		}

		for (int i = 0;i < 8;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny]) {
					q.push({ {nx,ny},cnt + 1 });
					visit[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == 0 && !dist[i][j]) {
				memset(visit, false, sizeof(visit));
				bfs(i, j);
			}
		}
	}
	cout << result;
}