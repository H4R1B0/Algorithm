#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 91


int arr[MAX];
long long dp[MAX];

int main() {
	
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3;i < MAX;i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}