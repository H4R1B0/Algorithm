#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
int dp[10][MAX];

void setting() {
	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
}

void func() {
	for (int i = 2; i < MAX; i++) {
		for (int j = 0; j < 10; j++) {
			switch (j) {
			case 0:
				dp[j][i] = dp[7][i - 1];
				break;
			case 1:
				dp[j][i] = dp[2][i - 1] + dp[4][i - 1];
				break;
			case 2:
				dp[j][i] = dp[1][i - 1] + dp[3][i - 1] + dp[5][i - 1];
				break;
			case 3:
				dp[j][i] = dp[2][i - 1] + dp[6][i - 1];
				break;
			case 4:
				dp[j][i] = dp[1][i - 1] + dp[5][i - 1] + dp[7][i - 1];
				break;
			case 5:
				dp[j][i] = dp[2][i - 1] + dp[4][i - 1] + dp[6][i - 1] + dp[8][i - 1];
				break;
			case 6:
				dp[j][i] = dp[3][i - 1] + dp[5][i - 1] + dp[9][i - 1];
				break;
			case 7:
				dp[j][i] = dp[4][i - 1] + dp[8][i - 1] + dp[0][i - 1];
				break;
			case 8:
				dp[j][i] = dp[5][i - 1] + dp[7][i - 1] + dp[9][i - 1];
				break;
			case 9:
				dp[j][i] = dp[6][i - 1] + dp[8][i - 1];
				break;
			}
			dp[j][i] %= 1234567;
		}
	}
}

int main() {
	int T;
	cin >> T;
	setting();
	func();
	while (T--) {
		cin >> N;

		int result = 0;
		for (int i = 0;i < 10;i++)
			result += dp[i][N];
		cout << result % 1234567 << endl;
	}
}