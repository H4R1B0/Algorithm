#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int dp[MAX];

int main(void)
{
	dp[1] = 1;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int num;
		cin >> num;

		if (!dp[i])
			continue;

		for (int j = 1;(j <= num) && (i + j < MAX);j++) {
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0)
				dp[i + j] = dp[i] + 1;
		}
	}
	if (!dp[N])
		cout << -1;
	else
		cout << dp[N] - 1;
}