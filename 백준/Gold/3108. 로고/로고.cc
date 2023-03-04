#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];

void dfs(int x, int y) {
	if (x < 0 || x >= MAX || y < 0 || y >= MAX)
		return;
	if (map[x][y] == 2 || map[x][y] == 0)
		return;

	map[x][y] = 2;

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		dfs(nx, ny);
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;

		for (int j = x1;j <= x2;j++) {
			map[j][y1] = 1;
			map[j][y2] = 1;
		}
		for (int j = y1;j <= y2;j++) {
			map[x1][j] = 1;
			map[x2][j] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	if (map[1000][1000] == 2)
		cnt--;
	cout << cnt;
}