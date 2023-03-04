#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 31

int T;
int N, M;
int dp[MAX][MAX];


int main() {
	cin >> T;
	for (int i = 1;i <= 30;i++) {
		dp[1][i] = i;
	}

	for (int i = 2;i <= 30;i++) {
		for (int j = i;j <= 30;j++) {
			for (int k = 1;k < j;k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}


	for (int i = 0;i < T;i++) {
		cin >> N >> M;

		cout << dp[N][M] << endl;
	}
}