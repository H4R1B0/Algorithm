#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

#define endl '\n'
#define MAX 1000000+10
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> dp(1000000 + 1);
	dp[1] = 1, dp[2] = 2;

	cin >> N;
	if (N == 1 || N == 2) {
		cout << dp[N];
		return 0;
	}
	for (int i = 3;i <= N;i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= 15746;
	}
	cout << dp[N];
}