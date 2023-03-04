#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 301
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, X;
int map[MAX][MAX];
int melt_map[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + xd[i];
			int ny = cy + yd[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (!visit[nx][ny] && map[nx][ny] != 0)
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int melt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (map[nx][ny] == 0)
			cnt++;
	}
	return cnt;

}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];			
		}
	}

	int year = 0;
	while (true) {
		int cnt = 0;

		memset(visit, false, sizeof(visit));
		memset(melt_map, 0, sizeof(melt_map));

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (map[i][j] > 0 && !visit[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			cout << year << endl;
			return 0;
		}
			
		if (cnt == 0) {
			cout << 0 << endl;
			return 0;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] > 0)
				{
					melt_map[i][j] = map[i][j] - melt(i, j);
					if (melt_map[i][j] < 0)
						melt_map[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = melt_map[i][j];
			}
		}

		year++;
	}
}