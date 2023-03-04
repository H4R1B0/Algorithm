#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 17
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };
int xd[3] = { 0,1,1 };
int yd[3] = { 1,0,1 };

int N;
int map[MAX][MAX];
//0가로 1대각선 2 세로
int dp[MAX][MAX][3];
bool visit[MAX][MAX];

void DP() {
	for (int i = 1;i <= N;i++) {
		for (int j = 3;j <= N;j++) {
			//벽이 있는경우 패스
			if (map[i][j] == 1)
				continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];

			//맨위는 패스
			if (i == 1)
				continue;
			dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];

			//대각선 양쪽 1 패스
			if (map[i - 1][j] == 1 || map[i][j - 1] == 1)
				continue;
			dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= N;j++)
			cin >> map[i][j];

	dp[1][2][0] = 1;
	DP();
	int result = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	cout << result;
}