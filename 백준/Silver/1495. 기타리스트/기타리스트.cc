#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, S, M;
int arr[MAX];
int dp[MAX][1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S >> M;
	for (int i = 1;i <= N;i++)
		cin >> arr[i];

	dp[0][S]++;
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= M;j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= M)
					dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	int answer = -1;
	for (int i = 0;i <= M;i++) {
		if (dp[N][i])
			answer = max(answer, i);
	}
	cout << answer;
}