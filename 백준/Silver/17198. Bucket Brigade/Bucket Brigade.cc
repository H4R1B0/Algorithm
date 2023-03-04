#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 10+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
char g[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> B, R, L;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cin >> g[i][j];
			if (g[i][j] == 'B')
				B = { i,j };
			if (g[i][j] == 'R')
				R = { i,j };
			if (g[i][j] == 'L')
				L = { i,j };
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {B.first,B.second},0 });
	visit[B.first][B.second] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (g[x][y] == 'L') {
			cout << cnt-1;
			return 0;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
				if (!visit[nx][ny] && g[nx][ny] != 'R') {
					visit[nx][ny] = true;
					q.push({ {nx,ny},cnt + 1 });
				}
			}
		}
	}
}