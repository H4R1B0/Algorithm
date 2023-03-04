#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+10
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
int dp[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;
	int a = A.length();
	int b = B.length();

	for (int i = 1;i <= a;i++) {
		for (int j = 1;j <= b;j++) {
			if (A[i-1] == B[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[a][b] << endl;
	vector<char> answer;
	while (dp[a][b] != 0) {
		if (dp[a][b] == dp[a][b - 1]) //왼쪽 비교
			b--;
		else if (dp[a][b] == dp[a - 1][b]) //윗쪽 비교
			a--;
		else if (dp[a][b] - 1 == dp[a - 1][b - 1]) {
			answer.push_back(B[b - 1]);
			a--;
			b--;
		}
	}
	for (int i = answer.size() - 1;i >= 0;i--)
		cout << answer[i];
}