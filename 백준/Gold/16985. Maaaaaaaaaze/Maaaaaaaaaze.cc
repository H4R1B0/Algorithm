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
#define MAX 5+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 1,-1,0,0,0,0 };
int yd[] = { 0,0,1,-1,0,0 };
int zd[] = { 0,0,0,0,1,-1 };

int map[MAX][MAX][MAX];
int tmp[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int order[5] = { 0,1,2,3,4 };
int cnt[5];
bool visit[MAX][MAX][MAX];
int result = INF;

void rotate(int num, int op) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (op == 0)
				tmp[order[num]][i][j] = map[num][i][j];
			else if (op == 1)
				tmp[order[num]][i][j] = map[num][4 - j][i];
			else if (op == 2)
				tmp[order[num]][i][j] = map[num][4 - i][4 - j];
			else
				tmp[order[num]][i][j] = map[num][j][4 - i];
		}
	}
}

int bfs() {
	if (!tmp[0][0][0] || !tmp[4][4][4])
		return INF;

	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	visit[0][0][0] = true;
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0;i < 6;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			int nz = z + zd[i];

			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5) {
				if (tmp[nz][nx][ny] && !visit[nz][nx][ny]) {
					visit[nz][nx][ny] = true;
					dist[nz][nx][ny] = dist[z][x][y] + 1;
					if (nz == 4 && nx == 4 && ny == 4)
						return dist[4][4][4];
					q.push({ {nx,ny},nz });
				}
			}
		}
	}
	return INF;
}

void dfs(int idx) {
	if (idx == 5) {
		for (int i = 0;i < 5;i++)
			rotate(i, cnt[i]);
		result = min(result, bfs());
		return;
	}

	for (int i = 0;i < 4;i++) {
		cnt[idx] = i;
		dfs(idx + 1);
	}
}

int main() {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			for (int k = 0;k < 5;k++) {
				cin >> map[i][j][k];
			}
		}
	}

	do {
		dfs(0);
	} while (next_permutation(order, order + 5));

	if (result == INF)
		result = -1;
	cout << result;
}