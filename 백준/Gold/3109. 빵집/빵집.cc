#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };
int xd[3] = { -1,0,1 };
int yd[3] = { 1,1,1 };

int R, C, result;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool ans;

void dfs(int x, int y) {

	visit[x][y] = true;

	if (y == C - 1) {
		ans = true;
		result++;
		return;
	}

	for (int i = 0;i < 3;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			if (!visit[nx][ny] && map[nx][ny] == '.') {
				dfs(nx, ny);
				if (ans)
					return;
			}
		}
	}
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < R;i++) {
		ans = false;
		dfs(i, 0);
	}
	cout << result;
}