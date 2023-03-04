#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
bool dp[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
		dp[i][i] = true;
	}
	for (int i = 1;i < N;i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	for (int i = 2;i <= N - 1;i++) {
		for (int j = 1;j <= N - i;j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
		}
	}
	cin >> M;
	while (M--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << endl;
	}
}