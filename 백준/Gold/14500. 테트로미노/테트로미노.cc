#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { -1,0,1,0 };
int yd[4] = { 0,1,0,-1 };

int N, M;
int MAP[MAX][MAX];
bool visit[MAX][MAX];
int answer;

void dfs(int x, int y, int sum, int cnt) {
	visit[x][y] = true;

	if (cnt == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visit[nx][ny]) {
				dfs(nx, ny, sum + MAP[nx][ny], cnt + 1);
				visit[nx][ny] = false;
			}
		}
	}
}
//ㅗ
void shape1(int x, int y) {
	int sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x - 1][y + 1];
	answer = max(answer, sum);
}
//ㅜ
void shape2(int x, int y) {
	int sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x + 1][y + 1];
	answer = max(answer, sum);
}
//ㅏ
void shape3(int x, int y) {
	int sum = MAP[x][y] + MAP[x + 1][y] + MAP[x + 2][y] + MAP[x + 1][y + 1];
	answer = max(answer, sum);
}
//ㅓ
void shape4(int x, int y) {
	int sum = MAP[x][y] + MAP[x - 1][y + 1] + MAP[x][y + 1] + MAP[x + 1][y + 1];
	answer = max(answer, sum);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			memset(visit, false, sizeof(visit));
			dfs(i, j, MAP[i][j], 0);
			if (i >= 1 && j < M - 2)
				shape1(i, j);
			if (i < N - 1 && j < M - 2)
				shape2(i, j);
			if(i<N-2 && j<M-1)
				shape3(i, j);
			if(i>=1 && i<N-1&&j<M-1)
				shape4(i, j);
		}
	}
	cout << answer;
}