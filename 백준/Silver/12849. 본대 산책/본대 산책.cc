#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 8+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int D;
long long dp[MAX];

int main() {
	cin >> D;
	dp[1] = 1;
	while (D--) {
		long long tmp[MAX] = { 0, };

		for (int i = 0;i < 8;i++) {
			tmp[1] = dp[2] + dp[3];
			tmp[2] = dp[1] + dp[3] + dp[4];
			tmp[3] = dp[1] + dp[2] + dp[4] + dp[5];
			tmp[4] = dp[2] + dp[3] + dp[5] + dp[6];
			tmp[5] = dp[3] + dp[4] + dp[6] + dp[8];
			tmp[6] = dp[4] + dp[5] + dp[7];
			tmp[7] = dp[6] + dp[8];
			tmp[8] = dp[5] + dp[7];
		}

		for (int i = 1;i <= 8;i++) {
			dp[i] = tmp[i] % 1000000007;
		}
	}
	cout << dp[1];
}