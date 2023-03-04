#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
ll dp[MAX][21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> arr[i];

	dp[1][arr[1]]++;
	for (int i = 2;i < N;i++) {
		for (int j = 0;j <= 20;j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 1][arr[N]];
}