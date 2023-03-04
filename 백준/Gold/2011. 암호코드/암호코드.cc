#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 5000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
int dp[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	for (int i = 1;i <= s.length();i++)
		arr[i] = s[i - 1] - '0';
	if (s.length() == 1 && s[0] == '0') {
		cout << 0;
		return 0;
	}
	dp[0] = 1;
	for (int i = 1;i <= s.length();i++) {
		if (arr[i] >= 1 && arr[i] <= 9)
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;
		if (i == 1)
			continue;
		int tmp = arr[i - 1] * 10 + arr[i];
		if (tmp >= 10 && tmp <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
	}
	cout << dp[s.length()];
}