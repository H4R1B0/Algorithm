#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 501

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int result;
int map[MAX][MAX];
int dp[MAX][MAX];

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if(map[x][y] > map[nx][ny])
				dp[x][y] = dp[x][y] + dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {

	cin >> N >> M;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	cout << dfs(0, 0) << endl;
}