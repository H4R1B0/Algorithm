#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
ll dp[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1;i <= 200;i++) {
		dp[i][1] = i;
	}
	for (int i = 1;i <= 200;i++) {
		dp[1][i] = 1;
	}
	for (int i = 2;i <= 200;i++) {
		for (int j = 2;j <= 200;j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 1000000000;
		}
	}
	cin >> N >> K;
	cout << dp[K][N];
}