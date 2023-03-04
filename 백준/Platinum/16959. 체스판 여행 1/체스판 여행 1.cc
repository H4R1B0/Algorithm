#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 10+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int Knight_xd[] = { -2,-1,1,2,2,1,-1,-2 };
int Knight_yd[] = { 1,2,2,1,-1,-2,-2,-1 };
int Bishop_xd[4] = { -1,1,1,-1 };
int Bishop_yd[4] = { 1,1,-1,-1 };
int Rook_xd[4] = { 0,-1,0,1 };
int Rook_yd[4] = { 1,0,-1,0 };

struct INFO {
	int x, y, cur, horse;
};

int N;
int g[MAX][MAX];
int visit[MAX][MAX][101][3];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, -1, sizeof(visit));
	queue<INFO> q;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> g[i][j];
			if (g[i][j] == 1) {
				for (int k = 0;k < 3;k++) {
					visit[i][j][1][k] = 0;
					q.push({ i,j,1,k });
				}
			}
		}
	}

	int ans = -1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cur = q.front().cur;
		int horse = q.front().horse;
		q.pop();

		if (cur == N * N) {
			if (ans == -1 || ans > visit[x][y][cur][horse]) {
				ans = visit[x][y][cur][horse];
			}
		}

		for (int i = 0;i < 3;i++) {
			if (horse == i)
				continue;
			if (visit[x][y][cur][i] == -1) {
				visit[x][y][cur][i] = visit[x][y][cur][horse] + 1;
				q.push({ x,y,cur,i });
			}
		}

		if (horse == 0) {
			for (int i = 0;i < 8;i++) {
				int nx = x + Knight_xd[i];
				int ny = y + Knight_yd[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					int next = cur;
					if (g[nx][ny] == cur + 1) {
						next = cur + 1;
					}

					if (visit[nx][ny][next][horse] == -1) {
						visit[nx][ny][next][horse] = visit[x][y][cur][horse] + 1;
						q.push({ nx,ny,next,horse });
					}
				}
			}
		}
		else if (horse == 1) {
			for (int i = 0;i < 4;i++) {
				for (int k = 1;;k++ ) {
					int nx = x + Bishop_xd[i] * k;
					int ny = y + Bishop_yd[i] * k;

					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						int next = cur;
						if (g[nx][ny] == cur + 1) {
							next = cur + 1;
						}

						if (visit[nx][ny][next][horse] == -1) {
							visit[nx][ny][next][horse] = visit[x][y][cur][horse] + 1;
							q.push({ nx,ny,next,horse });
						}
					}
					else
						break;
				}
			}
		}
		else if (horse == 2) {
			for (int i = 0; i < 4; i++) {
				for (int k = 1; ; k++) {
					int nx = x + Rook_xd[i] * k;
					int ny = y + Rook_yd[i] * k;

					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						int next = cur;
						if (g[nx][ny] == cur + 1) {
							next = cur + 1;
						}
						if (visit[nx][ny][next][horse] == -1) {
							visit[nx][ny][next][horse] = visit[x][y][cur][horse] + 1;
							q.push({ nx,ny,next,horse });
						}
					}
					else
						break;
				}
			}
		}
	}

	cout << ans;
	return 0;
}