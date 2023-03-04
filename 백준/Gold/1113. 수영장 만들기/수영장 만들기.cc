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
#define MAX 50+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
int water[MAX][MAX];
int max_height = 0;
int min_height = 10;
bool visit[MAX][MAX];

void bfs(int a, int b, int height) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		water[x][y]--;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (visit[nx][ny])
				continue;
			if (nx == 0 || nx == N - 1 || ny == 0 || ny == M - 1)
				continue;

			if (map[nx][ny] + water[nx][ny] == height && water[nx][ny] > 0) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}

void Solve() {
	for (int h = max_height;h > min_height;h--) {
		memset(visit, false, sizeof(visit));

		for (int i = 1;i < N - 1;i++) {
			for (int j = 1;j < M - 1;j++) {
				if (water[i][j] > 0 && !visit[i][j]) {
					for (int k = 0;k < 4;k++) {
						int nx = i + xd[k];
						int ny = j + yd[k];

						if (map[nx][ny] + water[nx][ny] < map[i][j] + water[i][j]) {
							bfs(i, j, h);
							break;
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < M;j++) {
			map[i][j] = str[j] - '0';
			water[i][j] = 0;

			max_height = max(max_height, map[i][j]);
			min_height = min(min_height, map[i][j]);
		}
	}

	for (int i = 1;i < N - 1;i++) {
		for (int j = 1;j < M - 1;j++) {
			water[i][j] = max_height - map[i][j];
		}
	}

	Solve();

	int result = 0;
	for (int i = 1;i < N - 1;i++) {
		for (int j = 1;j < M - 1;j++) {
			result += water[i][j];
			//cout << water[i][j];
		}
		//cout << endl;
	}
	cout << result;
}