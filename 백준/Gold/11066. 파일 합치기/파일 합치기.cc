#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int sum[MAX], dp[MAX][MAX], arr[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1;i <= N;i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N - i;j++) {
				dp[j][i + j] = INF;
				for (int k = j;k < i + j;k++) {
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][N] << endl;
	}
}