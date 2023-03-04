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
#define MAX 1000000+10
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> t(17), p(17);
	for (int i = 1;i <= N;i++) {
		cin >> t[i] >> p[i];
	}
	vector<int> dp(17,0);
	int answer=0;
	for (int i = 1;i <= N;i++) {
		if (i + t[i] <= N + 1) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			answer = max(answer, dp[i + t[i]]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
		answer = max(answer, dp[i + 1]);
	}
	cout << answer;
}