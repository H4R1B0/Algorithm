#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"
#define MAX 10+1
#define INF 987654321
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
int dist[MAX][MAX][2];
vector<pair<int, int>> zero_v;

void check_zero() {
	for (int i = 0;i < zero_v.size();i++) {
		int x = zero_v[i].first;
		int y = zero_v[i].second;

		int garo_cnt = 0;
		for (int k = 0;k < 2;k++) {
			int nx = x + xd[k];
			int ny = y + yd[k];

			if (map[nx][ny] != 1)
				garo_cnt++;
		}

		int sero_cnt = 0;
		for (int k = 2;k < 4;k++) {
			int nx = x + xd[k];
			int ny = y + yd[k];

			if (map[nx][ny] != 1)
				sero_cnt++;
		}

		if (garo_cnt >= 1 && sero_cnt >= 1)
			map[x][y] = -1;
	}
}

int Set_Time(int Cur_Time, int Period) {
	int R_Value = Cur_Time;
	while (1) {
		if (R_Value % Period == 0) break;
		R_Value++;
	}
	return R_Value;
}

void bfs() {
	queue<pair<pair<int, int>, pair<bool, bool>>> q;
	q.push({ {0,0},{false,false} });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool bridge = q.front().second.first;
		bool before_state = q.front().second.second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (map[nx][ny] == -1)
				continue;

			if (map[nx][ny] == 1) {
				if (dist[nx][ny][bridge] > dist[x][y][bridge] + 1) {
					dist[nx][ny][bridge] = dist[x][y][bridge] + 1;
					q.push({ {nx,ny}, {bridge,false} });
				}
			}
			else if (map[nx][ny] == 0) {
				if (bridge == false && before_state == false) {
					int Temp_Time = Set_Time(dist[x][y][bridge] + 1, M);
					if (dist[nx][ny][1] > Temp_Time) {
						dist[nx][ny][1] = Temp_Time;
						q.push(make_pair(make_pair(nx, ny), make_pair(true, true)));
					}
				}
			}
			else if (map[nx][ny] >= 2) {
				if (before_state == false) {
					int Temp_Time = Set_Time(dist[x][y][bridge] + 1, map[nx][ny]);
					if (dist[nx][ny][bridge] > Temp_Time) {
						dist[nx][ny][bridge] = Temp_Time;
						q.push(make_pair(make_pair(nx, ny), make_pair(bridge, true)));
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				zero_v.push_back({ i,j });
			dist[i][j][0] = INF;
			dist[i][j][1] = INF;
		}
	}

	bfs();

	cout << min(dist[N - 1][N - 1][0], dist[N - 1][N - 1][1]);
}
