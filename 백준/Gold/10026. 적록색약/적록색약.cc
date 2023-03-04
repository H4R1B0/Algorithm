#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX 101

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int cnt;

char map[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int x, int y, char c) {
	visit[x][y] = true;

	for (int i = 0;i < 4;i++) {
		int newX = x + xd[i];
		int newY = y + yd[i];

		if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
			if (map[newX][newY]==c && !visit[newX][newY]) {
				dfs(newX, newY,c);
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visit[i][j]) {
				dfs(i,j,map[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	cnt = 0;

	memset(visit, false, sizeof(visit));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (map[i][j]=='G') {
				map[i][j] = 'R';
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visit[i][j]) {
				dfs(i, j, map[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}