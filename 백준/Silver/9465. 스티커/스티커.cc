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

int N, M;
int dp[2][MAX];
int arr[2][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0;i < 2;i++) {
			for (int j = 1;j <= N;j++) {
				cin >> arr[i][j];
			}
		}
		
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1], dp[1][1] = arr[1][1];
		for (int i = 2;i <= N;i++) {
			dp[0][i] = max(dp[1][i-1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i - 2]) + arr[1][i];
		}
		cout << max(dp[0][N], dp[1][N]) << endl;
	}
}