#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 30+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
int Max;
int map[MAX][MAX];
int result_map[MAX][MAX];
bool visit[MAX][MAX];

bool bfs(int a, int b, int num) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ a,b });
	v.push_back({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && map[nx][ny] == map[x][y]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					v.push_back({ nx,ny });
				}
			}
		}
	}

	for (int i = 0;i < v.size();i++) {
		int x = v[i].first;
		int y = v[i].second;

		map[x][y] = num;
	}


	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] != result_map[i][j])
				return false;
		}
	}
	return true;
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
			cin >> result_map[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] != result_map[i][j]) {
				if (bfs(i, j, result_map[i][j])) {
					cout << "YES";
					return 0;
				}
				else {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
}