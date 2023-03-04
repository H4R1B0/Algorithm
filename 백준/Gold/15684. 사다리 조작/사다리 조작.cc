#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 9

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M, H;
int answer = 4;
bool visit[31][11];

bool check() {
	for (int j = 1;j <= N;j++) {
		int col = j;
		for (int i = 1;i <= H;i++) {
			if (visit[i][col])
				col++;
			else if (visit[i][col - 1])
				col--;
		}
		if (col != j)
			return false;
	}
	return true;
}

void dfs(int depth, int cnt) {
	if (depth == cnt) {
		if (check()) {
			cout << depth;
			exit(0);
		}
		return;
	}
	for (int j = 1;j < N;j++) {
		for (int i = 1;i <= H;i++) {
			if (visit[i][j] || visit[i][j - 1] || visit[i][j + 1])
				continue;
			visit[i][j] = true;
			dfs(depth, cnt + 1);
			visit[i][j] = false;

			while (!visit[i][j - 1] && !visit[i][j + 1])
				i++;
		}
	}
	return;
}

int main(void) {
	cin >> N >> M >> H;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		visit[a][b] = true;
	}
	for (int i = 0;i < 4;i++) {
		dfs(i, 0);
	}
	if (answer >= 4)
		cout << -1;
	else
		cout << answer;
}