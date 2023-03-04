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
#define MAX 1000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int dp[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < 10;i++)
		dp[1][i] = 1;
	for (int i = 2;i <= N;i++) {
		dp[i][9] = 1;
		for (int j = 8;j >= 0;j--) {
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
			dp[i][j] %= 10007;
		}
	}
	int sum = 0;
	for (int i = 0;i < 10;i++) {
		sum += dp[N][i];
		sum %= 10007;
	}
	cout << sum;
}