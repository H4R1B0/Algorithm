#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int dp[MAX];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dp[0] = 1, dp[1]=3;
	for (int i = 2;i <= N;i++) {
		dp[i] = dp[i - 1] * 2 + dp[i - 2];
		dp[i] %= 9901;
	}
	cout << dp[N];
}