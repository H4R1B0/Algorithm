#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001

int xd[] = { 0,0,1,-1};
int yd[] = { 1,-1,0,0 };

int N, M;
bool map[MAX][MAX];
int visit[MAX][MAX][2];

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,1},1 });
	visit[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == N && y == M) {
			return visit[x][y][block];
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (map[nx][ny] == 1 && block == 1) {
					visit[nx][ny][block - 1] = visit[x][y][block] + 1;
					q.push({ {nx,ny},block - 1 });
				}
				if (map[nx][ny] == 0 && !visit[nx][ny][block]) {
					visit[nx][ny][block] = visit[x][y][block] + 1;
					q.push({ {nx,ny},block });
				}
			}
		}
	}
	return -1;
}



int main() {
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < M;j++) {
			map[i][j+1] = s[j]-'0';
		}
	}

	cout << bfs() << endl;
}