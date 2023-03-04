#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int min_dp[3];
int max_dp[3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> max_dp[0] >> max_dp[1] >> max_dp[2];
	min_dp[0] = max_dp[0], min_dp[1] = max_dp[1], min_dp[2] = max_dp[2];
	for (int i = 1;i < N;i++) {
		int input[3], tmp[3];
		cin >> input[0] >> input[1] >> input[2];
		tmp[0] = max_dp[0], tmp[1] = max_dp[1], tmp[2] = max_dp[2];
		max_dp[0] = max(tmp[0], tmp[1]) + input[0];
		max_dp[1] = max({ tmp[0],tmp[1],tmp[2] }) + input[1];
		max_dp[2] = max(tmp[1], tmp[2]) + input[2];

		tmp[0] = min_dp[0], tmp[1] = min_dp[1], tmp[2] = min_dp[2];
		min_dp[0] = min(tmp[0], tmp[1]) + input[0];
		min_dp[1] = min({ tmp[0],tmp[1],tmp[2] }) + input[1];
		min_dp[2] = min(tmp[1], tmp[2]) + input[2];
	}
	cout << max({ max_dp[0],max_dp[1],max_dp[2] }) << " ";
	cout << min({ min_dp[0],min_dp[1],min_dp[2] }) << " ";
}