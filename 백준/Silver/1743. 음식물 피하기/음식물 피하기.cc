#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
int result;
char map[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (!visit[nx][ny] && map[nx][ny] == '#') {
					q.push({ nx,ny });
					visit[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
	result = max(result, cnt);
}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			map[i][j] = '.';
		}
	}
	for (int i = 1;i <= K;i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = '#';
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (!visit[i][j] && map[i][j] == '#') {
				bfs(i,j);
			}
		}
	}
	cout << result;
}