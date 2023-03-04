#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 501


int arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
	
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 1;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + arr[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j-1] + arr[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}
	}
	int result = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j <= i;j++) {
			result = max(result, dp[i][j]);
		}
	}
	cout << result;
}