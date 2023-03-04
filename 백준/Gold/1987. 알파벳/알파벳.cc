#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX 21

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int R, C;
int result;
char map[MAX][MAX];
bool visit[26];


void dfs(int x, int y, int cnt) {

	result = max(result, cnt);

	for (int i = 0;i < 4;i++) {
		int newX = x + xd[i];
		int newY = y + yd[i];

		if (newX >= 0 && newX < R && newY >= 0 && newY < C) {
			if (visit[map[newX][newY] - 'A'] == false) {
				visit[map[newX][newY] - 'A'] = true;
				dfs(newX, newY, cnt + 1);
				visit[map[newX][newY] - 'A'] = false;
			}
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
		}
	}
	visit[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << result << endl;
}