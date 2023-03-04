#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 15+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, S, M, K;
int arr[MAX];
int dp[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	dp[0][0] = 1;
	for (int i = 1;i < N;i++)
		dp[i][0] = 1;
	for (int i = 1;i < M;i++)
		dp[0][i] = 1;
	for (int i = 1;i < N;i++) {
		for (int j = 1;j < M;j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	if (K != 0) {
		int x = K / M, y = K % M - 1;
		int answer = dp[x][y] * dp[N - x - 1][M - y - 1];
		cout << answer;
	}
	else {
		cout << dp[N-1][M-1];
	}
}