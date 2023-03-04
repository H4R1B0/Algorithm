#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 501
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


int N, result;
int map[MAX][MAX];
int dp[MAX][MAX];

int dfs(int x, int y) {
	if (dp[x][y] != 0)
		return dp[x][y];
	dp[x][y] = 1;

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] > map[x][y]) {
				dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
			}
		}
	}
	return dp[x][y];
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			result = max(result, dfs(i, j));
		}
	}

	cout << result;
}