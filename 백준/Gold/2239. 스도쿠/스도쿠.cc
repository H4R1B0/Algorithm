#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 501
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N;
int MAP[9][9];
bool Row[9][9];
bool Col[9][9];
bool Square[9][9];

void dfs(int cnt) {
	int x = cnt / 9;
	int y = cnt % 9;
	if (cnt == 81) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				cout << MAP[i][j];
			}
			cout << endl;
		}
		exit(0);
	}
	if (MAP[x][y] == 0) {
		for (int i = 1;i <= 9;i++) {
			if (!Row[x][i] && !Col[y][i] && !Square[(x / 3) * 3 + (y / 3)][i]) {
				Row[x][i] = true;
				Col[y][i] = true;
				Square[(x / 3) * 3 + (y / 3)][i] = true;
				MAP[x][y] = i;
				dfs(cnt + 1);
				Row[x][i] = false;
				Col[y][i] = false;
				Square[(x / 3) * 3 + (y / 3)][i] = false;
				MAP[x][y] = 0;
			}
		}
	}
	else {
		dfs(cnt + 1);
	}
	
}

int main(void) {
	for (int i = 0;i < 9;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < 9;j++) {
			MAP[i][j] = s[j] - '0';
			if (MAP[i][j] != 0) {
				Row[i][MAP[i][j]] = true;
				Col[j][MAP[i][j]] = true;
				Square[(i / 3) * 3 + (j / 3)][MAP[i][j]] = true;
			}
		}
	}
	dfs(0);
}