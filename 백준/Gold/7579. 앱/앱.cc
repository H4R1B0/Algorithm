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
int arr[MAX][2];
int dp[MAX][10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		cin >> arr[i][0];
	for (int i = 1;i <= N;i++) {
		cin >> arr[i][1];
		sum += arr[i][1];
	}
		
	for (int i = 1;i <= N;i++) {
		int m = arr[i][0];
		int c = arr[i][1];
		for (int j = 0;j <= sum;j++) {
			if (j < c)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c] + m);
		}
	}
	for (int i = 0;i <= sum;i++) {
		if (dp[N][i] >= M) {
			cout << i;
			break;
		}			
	}
}