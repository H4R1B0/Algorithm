#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 101
#define INF 987654321

int xd[] = { -1,1,0,0,0,0 };
int yd[] = { 0,0,1,-1,0,0 };
int zd[] = { 0,0,0,0,1,-1 };

int N, M, H;
int arr[MAX][MAX][MAX];
int total, days;
queue<tuple<int, int, int>> q;

int bfs() {
	while (!q.empty()) {
		int qsize = q.size();
		total += qsize;
		if (total == N * M * H) {
			return days;
		}
		for (int i = 0; i < qsize; i++) {
			int x = get<1>(q.front());
			int y = get<2>(q.front());
			int z = get<0>(q.front());
			q.pop();
			for (int k = 0; k < 6; k++) {
				int next_x = x + xd[k];
				int next_y = y + yd[k];
				int next_z = z + zd[k];
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && next_z >= 0 && next_z < H && arr[next_z][next_x][next_y] == 0) {
					arr[next_z][next_x][next_y] = 1;
					q.push(make_tuple(next_z, next_x, next_y));
				}
			}
		}
		days++;
	}
	if (total != N * M * H)
		return -1;
	return days;
}

int main() {
	cin >> M >> N >> H;

	for (int i = 0;i < H;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < M;k++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
				}

				else if (arr[i][j][k] == -1) {
					total++;
				}
			}
		}
	}

	cout << bfs() << endl;
}