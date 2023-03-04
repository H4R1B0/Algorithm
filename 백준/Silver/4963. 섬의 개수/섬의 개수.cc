#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX 51

int xd[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int yd[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

int w, h;
int cnt;
bool map[MAX][MAX];
bool visit[MAX][MAX];


void dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0;i < 8;i++) {
		int newX = x + xd[i];
		int newY = y + yd[i];

		if (newX >= 0 && newX < h && newY >= 0 && newY < w) {
			if (map[newX][newY]==1 && !visit[newX][newY])
				dfs(newX, newY);
		}
	}
}

int main() {

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;

		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cnt = 0;
	}
}