#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101
#define MOD 1000000000

long long dp[MAX][11];

int main() {
	
	for (int i = 1;i <= 9;i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;

	int n;
	cin >> n;

	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % MOD;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}

	long long sum = 0;
	for (int i = 0;i < 10;i++)
		sum += dp[n][i];
		
	
	cout << sum % MOD;
}