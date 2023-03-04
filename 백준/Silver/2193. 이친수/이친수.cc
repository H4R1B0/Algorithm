#include <iostream>
using namespace std;
long long dp[91] = {0,1};
int main() {
	int n,i;
	cin >> n;
	for (i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}