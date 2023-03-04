#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int g[MAX][MAX];
ll dp[MAX][MAX];

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
	dp[0][0] = 1;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (dp[i][j] == 0)
				continue;
			if (i == N - 1 && j == N - 1)
				continue;
			int value = g[i][j];
			int down = value + i;
			int right = value + j;
			if (down < N)
				dp[down][j] = dp[down][j] + dp[i][j];
			if(right < N)
				dp[i][right] = dp[i][right] + dp[i][j];

		}
	}
	cout << dp[N - 1][N - 1];
}