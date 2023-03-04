#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

struct INFO {
	int x, y;
	int cnt = 1;
	int wall = 0;
};

int N, M, K;
int map[MAX][MAX];
bool visit[MAX][MAX][11];

int bfs() {
	queue<INFO> q;
	q.push({ 1,1,1,0 });
	visit[1][1][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int wall = q.front().wall;
		q.pop();

		if (x == N && y == M) {
			return cnt;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (map[nx][ny] == 0 && !visit[nx][ny][wall]) {
					visit[nx][ny][wall] = true;
					q.push({ nx,ny,cnt + 1,wall });
				}
				if (map[nx][ny] == 1 && !visit[nx][ny][wall+1]) {
					if (wall < K) {
						visit[nx][ny][wall + 1] = true;
						q.push({ nx,ny,cnt + 1,wall + 1 });
					}
				}
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) {
		string str;
		cin >> str;
		for (int j = 1;j <= str.size();j++) {
			map[i][j] = str[j - 1] - '0';
		}
	}
	cout << bfs();
}