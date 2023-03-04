#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N,M;
bool map[MAX][MAX];
bool visit[MAX][MAX];

int bfs() {
	queue<pair<pair<int, int>, int>>q;
	q.push({ {1,1},1 });
	visit[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == N && y == M) {
			return cnt;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && map[nx][ny]==1) {
				if (!visit[nx][ny]) {
					q.push({ { nx, ny },cnt + 1 });
					visit[nx][ny] = true;
				}
			}

		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		string s;
		cin >> s;
		for (int j = 1;j <= M;j++) {
			map[i][j] = s[j-1] - '0';
		}
	}

	cout<<bfs();
}