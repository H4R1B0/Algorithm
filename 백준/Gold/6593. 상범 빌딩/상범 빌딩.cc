#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 30+1
#define INF 987654321

int xd[6] = { 0,0,1,-1,0,0 };
int yd[6] = { 1,-1,0,0,0,0 };
int zd[6] = { 0,0,0,0,1,-1 };

int L, R, C;
char map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
pair<pair<int, int>, int> Start, End;

void bfs(int a,int b, int c) {
	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {a,b},{c,0 } });
	visit[a][b][c] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (map[x][y][z] == 'E') {
			cout << "Escaped in " << cnt << " minute(s)." << endl;
			return;
		}

		for (int i = 0;i < 6;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			int nz = z + zd[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)
				continue;
			if (map[nx][ny][nz] == '#')
				continue;

			if (!visit[nx][ny][nz]) {
				visit[nx][ny][nz] = true;
				q.push({ {nx,ny}, {nz,cnt + 1} });
			}
		}
	}

	cout << "Trapped!" << endl;
}

int main(void)
{
	while (true) {
		cin >> L >> R >> C;

		if (!L && !R && !C)
			break;

		memset(visit, false, sizeof(visit));
		for (int i = 0;i < L;i++) {
			for (int j = 0;j < R;j++) {
				for (int k = 0;k < C;k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
						Start = { {i,j},k };
					if (map[i][j][k] == 'E')
						End = { {i,j},k };
				}
			}
		}

		bfs(Start.first.first, Start.first.second, Start.second);

	}
}