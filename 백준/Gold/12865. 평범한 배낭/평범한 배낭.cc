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
#define MAX 100000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[101][2];
int dp[101][100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1;i <= N;i++) {
		int w = arr[i][0];
		int v = arr[i][1];
		for (int j = 1;j <= K;j++) {
			if (j < w)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
		}
	}
	cout << dp[N][K];
}