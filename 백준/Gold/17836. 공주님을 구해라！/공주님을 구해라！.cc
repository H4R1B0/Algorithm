#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M, T;
int result;
int map[MAX][MAX];
bool visit[MAX][MAX][2];

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {1,1}, {0,0} });
	visit[1][1][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int get = q.front().second.second;		
		q.pop();

		if (map[x][y] == 2)
			get = 1;

		if (x == N && y == M) {
			result = cnt;
			return;
		}			

		for (int i = 0; i < 4; i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (get == 1) {
					if (!visit[nx][ny][get]) {
						visit[nx][ny][get] = true;
						q.push({ {nx,ny}, {cnt + 1,get} });
					}
				}
				else {
					if (!visit[nx][ny][get] && map[nx][ny] != 1) {
						visit[nx][ny][get] = true;
						q.push({ {nx,ny}, {cnt + 1,get} });
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> map[i][j];
		}
	}

	bfs();
	if (result >= 1 && result <= T)
		cout << result;
	else
		cout << "Fail";
}