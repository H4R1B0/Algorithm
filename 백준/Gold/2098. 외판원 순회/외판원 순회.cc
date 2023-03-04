#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 16+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int Bit;
int g[MAX][MAX];
int dp[MAX][1 << MAX];

int dfs(int cur, int bit) {
	if (bit == Bit) {
		if (g[cur][0] == 0)
			return INF;
		else
			return g[cur][0];
	}
	if (dp[cur][bit] != -1)
		return dp[cur][bit];
	dp[cur][bit] = INF;
	for (int i = 0;i < N;i++) {
		if (g[cur][i] == 0)
			continue;
		if ((bit & (1 << i)) == (1 << i))
			continue;
		dp[cur][bit] = min(dp[cur][bit], g[cur][i] + dfs(i, bit | (1 << i)));
	}
	return dp[cur][bit];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> g[i][j];
		}
	}
	Bit = (1 << N) - 1;
	memset(dp, -1, sizeof(dp));
	cout<<dfs(0, 1);
}