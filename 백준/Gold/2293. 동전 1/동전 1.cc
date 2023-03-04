#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[101];
int dp[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1;i <= N;i++) {
		for (int j = arr[i];j <= K;j++) {
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}
	cout << dp[K];
}