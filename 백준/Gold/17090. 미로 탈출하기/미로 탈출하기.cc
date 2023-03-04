#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int result = 0;
int dp[MAX][MAX];
char map[MAX][MAX];

int GetDir(char A){
	if (A == 'U')
		return 3;
	else if
		(A == 'R') return 0;
	else if
		(A == 'D') return 2;
	else if
		(A == 'L') return 1;
}


int dfs(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	int dir = GetDir(map[x][y]);

	dp[x][y] = dfs(x + xd[dir], y + yd[dir]);
	return dp[x][y];
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			result += dfs(i, j);
		}
	}
	cout << result;
}