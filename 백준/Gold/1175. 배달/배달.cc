#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>

#define endl "\n"
#define MAX 50+1
#define INF INT_MAX
#define ll long long
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

struct INFO
{
	int x, y;
	int cnt, dir;
	bool C_visit;
	bool D_visit;
};

int N, M;
int result = INF;
char map[MAX][MAX];
bool visit[MAX][MAX][5][2][2];
pair<int, int> Start;

void bfs(int a, int b) {
	queue<INFO> q;
	q.push({ a,b,0,-1,0,0 });
	visit[a][b][4][0][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int dir = q.front().dir;
		bool C_visit = q.front().C_visit;
		bool D_visit = q.front().D_visit;
		q.pop();

		if (C_visit && D_visit) {
			result = cnt;
			return;
		}

		for (int i = 0;i < 4;i++) {
			if (dir == i)
				continue;

			int nx = x + xd[i];
			int ny = y + yd[i];
			bool nC_visit = C_visit;
			bool nD_visit = D_visit;

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (!visit[nx][ny][i][C_visit][D_visit] && map[nx][ny] != '#') {
					if (map[nx][ny] == 'C')
						nC_visit = true;
					if (map[nx][ny] == 'D')
						nD_visit = true;

					visit[nx][ny][i][nC_visit][nD_visit] = true;
					q.push({ nx, ny, cnt + 1, i, nC_visit, nD_visit });
				}
			}
		}
	}
}

int main(void) {
	int idx = 0;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				Start = { i,j };
				map[i][j] = '.';
			}
			if (map[i][j] == 'C') {
				idx++;
				if (idx == 2)
					map[i][j] = 'D';
			}
		}
	}

	bfs(Start.first, Start.second);

	if (result == INF)
		cout << -1;
	else
		cout << result;
}
