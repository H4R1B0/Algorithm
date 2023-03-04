#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int map[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int x, int y, int cnt) {
	visit[x][y] = true;
	map[x][y] = cnt;

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] && !visit[nx][ny])
				dfs(nx, ny, cnt);
		}
	}
}

int bfs(int cnt) {
	queue<pair<int, int >> q;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (map[i][j] == cnt) {
				visit[i][j] = true;
				q.push({ i,j });
			}
		}
	}

	int result = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0;i < qsize;i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0;j < 4;j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] && map[nx][ny] != cnt)
						return result;
					else if (!map[nx][ny] && !visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		result++;
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (map[i][j] && !visit[i][j]) {
				dfs(i, j, cnt++);
			}
		}
	}

	int result = INF;
	for (int i = 1;i < cnt;i++) {
		memset(visit, false, sizeof(visit));
		result = min(result, bfs(i));
	}

	cout << result;
}