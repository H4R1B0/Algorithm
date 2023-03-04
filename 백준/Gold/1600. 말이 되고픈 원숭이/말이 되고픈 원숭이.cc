#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 201
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };
int hxd[8] = { 1,2,2,1,-1,-2,-2,-1 };
int hyd[8] = { 2,1,-1,-2,-2,-1,1,2 };

int K, W, H;
int result = INF;
int map[MAX][MAX];
bool visit[MAX][MAX][31];

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {1,1},{0,0} });
	visit[1][1][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int kcnt = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == H && y == W) {
			cout << cnt;
			return;
		}

		if (kcnt < K) {
			for (int i = 0;i < 8;i++) {
				int nx = x + hxd[i];
				int ny = y + hyd[i];

				if (nx >= 1 && nx <= H && ny >= 1 && ny <= W && !visit[nx][ny][kcnt+1] && !map[nx][ny]) {
					q.push({ {nx,ny},{kcnt + 1,cnt + 1} });
					visit[nx][ny][kcnt+1] = true;
				}
			}
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= H && ny >= 1 && ny <= W && !visit[nx][ny][kcnt] && !map[nx][ny]) {
				q.push({ {nx,ny},{kcnt,cnt + 1} });
				visit[nx][ny][kcnt] = true;
			}
		}
	}
	cout << -1;
	return;
}

int main() {
	cin >> K >> W >> H;
	for (int i = 1;i <= H;i++) {
		for (int j = 1;j <= W;j++) {
			cin >> map[i][j];
		}
	}
	bfs();
}