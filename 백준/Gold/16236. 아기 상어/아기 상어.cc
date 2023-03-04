#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 21

int xd[4] = { 0,0,-1,1 };
int yd[4] = { 1,-1,0,0 };

int N, answer;
int map[MAX][MAX];
int sharkX, sharkY, sharkSize = 2, eatCnt;
int minX, minY, minDis;
int visit[MAX][MAX];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (visit[nx][ny] != -1 || map[nx][ny] > sharkSize)
				continue;

			visit[nx][ny] = visit[x][y] + 1;

			if (map[nx][ny] != 0 && map[nx][ny] < sharkSize) {
				if (minDis > visit[nx][ny]) {
					minX = nx;
					minY = ny;
					minDis = visit[nx][ny];
				}
				else if (minDis == visit[nx][ny]) {
					if (minX == nx) {
						if (minY > ny) {
							minX = nx;
							minY = ny;
						}
					}
					else if (minX > nx) {
						minX = nx;
						minY = ny;
					}
				}
			}
			q.push({ nx,ny });
		}
	}
}
int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				sharkX = i;
				sharkY = j;
				map[i][j] = 0;
			}
		}
	}

	while (true) {
		memset(visit, -1, sizeof(visit));
		minX = minY = MAX;
		minDis = MAX * MAX;

		bfs(sharkX, sharkY);

		if (minX != MAX && minY != MAX) {
			answer += visit[minX][minY];
			eatCnt++;
			if (eatCnt == sharkSize) {
				sharkSize++;
				eatCnt = 0;
			}
			map[minX][minY] = 0;
			sharkX = minX;
			sharkY = minY;
		}

		else {
			break;
		}
	}

	cout << answer;
}