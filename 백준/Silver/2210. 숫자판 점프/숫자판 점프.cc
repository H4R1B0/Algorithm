#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 5+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int map[MAX][MAX];
int result;
bool visit[1000001];

void dfs(int x, int y, int sum, int cnt) {
	if (cnt == 6) {
		if (!visit[sum]) {
			visit[sum] = true;
			result++;
		}
		return;
	}

	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			dfs(nx, ny, sum * 10 + map[nx][ny], cnt + 1);
		}
	}
}

int main(void)
{
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			dfs(i, j, map[i][j], 1);
		}
	}
	cout << result;
}