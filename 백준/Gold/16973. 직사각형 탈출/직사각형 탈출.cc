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
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, H, W;
int Sx, Sy, Fx, Fy;
int map[MAX][MAX];
bool visit[MAX][MAX];

bool check(int x, int y, int dir) {
	if (dir == 0) {
		int ny = y + W - 1;
		if (ny > M)
			return false;

		for (int i = x; i < x + H; i++) {
			if (map[i][ny] == 1)
				return false;
		}
	}
	else if (dir == 1) {
		for (int i = x; i < x + H; i++) {
			if (map[i][y] == 1)
				return false;
		}
	}
	else if (dir == 2) {
		int nx = x + H - 1;
		if (nx > N)
			return false;

		for (int i = y; i < y + W; i++) {
			if (map[nx][i] == 1)
				return false;
		}
	}
	else if (dir == 3) {
		for (int i = y; i < y + W; i++) {
			if (map[x][i] == 1)
				return false;
		}
	}

	return true;
}

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {Sx,Sy},0 });
	visit[Sx][Sy] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		//cout << x << " " << y << endl;

		if (x == Fx && y == Fy) {
			return cnt;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (!visit[nx][ny]) {
					if (check(nx, ny, i)) {
						visit[nx][ny] = true;
						q.push({ {nx,ny},cnt + 1 });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> map[i][j];
		}
	}
	cin >> H >> W >> Sx >> Sy >> Fx >> Fy;

	cout << bfs();
}