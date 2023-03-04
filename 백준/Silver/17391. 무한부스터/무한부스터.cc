#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 300+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

struct INFO
{
	int x, y, cnt;
};

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];

int bfs() {
	queue<INFO> q;
	q.push({ 0,0,0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (x == N - 1 && y == M - 1)
			return cnt;

		int dist = map[x][y];
		for (int i = 0;i < 2;i++) {
			for (int k = 1;k <= dist;k++) {
				int nx = x + xd[i] * k;
				int ny = y + yd[i] * k;

				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny,cnt + 1 });
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs();
}