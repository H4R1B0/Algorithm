#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 51
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int R, C;
char map[MAX][MAX];
bool visit[MAX][MAX];
int Dx, Dy;
queue<pair<int, int>> water;
queue<pair<int, int>> start;

void bfs() {
	int cnt = 0;
	while (!start.empty()) {
		cnt++;

		int water_size = water.size();
		while (water_size--) {
			int wx = water.front().first;
			int wy = water.front().second;
			water.pop();

			for (int i = 0;i < 4;i++) {
				int nwx = wx + xd[i];
				int nwy = wy + yd[i];

				if (nwx < 0 || nwx >= R || nwy < 0 || nwy >= C) continue;
				if (map[nwx][nwy] == 'X' || map[nwx][nwy] == 'D' || map[nwx][nwy] == '*') continue;
				water.push(make_pair(nwx, nwy));
				map[nwx][nwy] = '*';
			}
		}

		int start_size = start.size();
		while (start_size--) {
			int sx = start.front().first;
			int sy = start.front().second;
			start.pop();
			visit[sx][sy] = true;

			if (sx == Dx && sy == Dy) {
				cout << cnt - 1;
				return;
			}

			for (int i = 0;i < 4;i++) {
				int nsx = sx + xd[i];
				int nsy = sy + yd[i];

				if (nsx < 0 || nsx >= R || nsy < 0 || nsy >= C) continue;
				if (map[nsx][nsy] == 'X' || map[nsx][nsy] == '*' || visit[nsx][nsy]) continue;
				visit[nsx][nsy] = true;
				start.push(make_pair(nsx, nsy));
			}
		}
	}

	cout << "KAKTUS";
}

int main() {
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				Dx = i;
				Dy = j;
			}
			if (map[i][j] == 'S') {
				start.push({ i,j });
			}
			if (map[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}

	bfs();
}