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
int height;

int map[MAX][MAX];
bool visit[MAX][MAX];


void dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0;i < 4;i++) {
		int newX = x + xd[i];
		int newY = y + yd[i];

		if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
			if (map[newX][newY] > height && !visit[newX][newY])
				dfs(newX, newY);
		}
	}
}

int main() {
	int result=1, cnt;
	cin >> N;
	int hmax = 1, hmin = 100;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			hmin = min(hmin, map[i][j]);
			hmax = max(hmax, map[i][j]);
				
		}
	}

	for (int h = hmin;h <= hmax;h++) {
		height = h;
		memset(visit, false, sizeof(visit));
		cnt = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (map[i][j] > h && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		result = max(result, cnt);
	}
	cout << result;
	
}