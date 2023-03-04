#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int dp[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[2] = 3;
	int idx = 1;
	for (int i = 4;i <= 30;i += 2) {
		dp[i] += dp[i - 2] * 3;
		for (int j = i - 4;j >= 0;j -= 2) {
			dp[i] += 2 * dp[j];
		}
		dp[i] += 2;
	}
	cin >> N;
	if (N % 2 == 1)
		cout << 0;
	else
		cout << dp[N];
}