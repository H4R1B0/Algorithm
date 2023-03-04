#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];
int result;

int dfs(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 0)
		return 0;
	if (visit[x][y] == true) {
		cout << -1 << endl;
		exit(0);
	}
	if (dp[x][y] != -1)
		return dp[x][y];

	visit[x][y] = true;
	dp[x][y] = 0;
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i]*map[x][y];
		int ny = y + yd[i]*map[x][y];
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visit[x][y] = false;
	return dp[x][y];
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string str;cin >> str;
		for (int j = 0;j < str.length();j++) {
			if (str[j] == 'H')
				map[i][j] = 0;
			else
				map[i][j] = str[j] - '0';
		}
	}
	memset(dp, -1, sizeof(dp));
	result = dfs(0, 0);
	cout << result;
}