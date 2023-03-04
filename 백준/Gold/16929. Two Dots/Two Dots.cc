#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool flag = false;

void dfs(int x, int y, int dir, int cnt, int sx, int sy) {
	if (flag)
		return;

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visit[nx][ny]) {
				if (map[nx][ny] == map[x][y]) {
					visit[nx][ny] = true;
					if (i == dir)
						dfs(nx, ny, dir, cnt, sx, sy);
					else
						dfs(nx, ny, dir, cnt + 1, sx, sy);
				}
			}
			else {
				if (nx == sx && ny == sy && cnt >= 4) {
					flag = true;
					return;
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			
			//int startX = i;
			//int startY = j;

			for (int k = 0;k < 4;k++) {
				memset(visit, false, sizeof(visit));
				visit[i][j] = true;
				dfs(i, j, k, 1, i, j);
				if (flag) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}