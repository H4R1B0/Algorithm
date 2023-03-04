#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int dp[MAX];
int before[MAX];

int main(void)
{
	cin >> N;
	
	dp[1] = 0;
	for (int i = 2;i <= N;i++) {
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;

		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				before[i] = i / 3;
			}
		}

		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				before[i] = i / 2;
			}
		}
	}
	cout << dp[N] << endl;
	while (N) {
		cout << N << " ";
		N = before[N];
	}
}