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
	vector<int> arr(N + 1);
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	vector<int> dp(N + 1, 0);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= i;j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	cout << dp[N];
}