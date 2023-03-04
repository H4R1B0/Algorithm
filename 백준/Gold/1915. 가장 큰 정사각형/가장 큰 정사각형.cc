#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX][MAX];
int dp[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		string s;
		cin >> s;
		for (int j = 1;j <= M;j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	int answer = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j]) {
				arr[i][j] = min({ arr[i - 1][j - 1],arr[i - 1][j],arr[i][j - 1] }) + 1;
			}
			answer = max(answer, arr[i][j]);
		}
	}
	cout << answer*answer;
}