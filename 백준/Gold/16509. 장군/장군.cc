#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 5+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[8] = { -3,-2,2,3,3,2,-2,-3 };
int yd[8] = { 2,3,3,2,-2,-3,-3,-2 };

int R1, C1, R2, C2;
int visit[10][9];

bool check(int x, int y, int dir) {

	if (dir == 0 || dir == 1) {
		for (int i = 1;i <= 2;i++) {
			if (x + i == R2 && y - i == C2)
				return false;
		}
	}
	if (dir == 2 || dir == 3) {
		for (int i = 1;i <= 2;i++) {
			if (x - i == R2 && y - i == C2)
				return false;
		}
	}
	if (dir == 4 || dir == 5) {
		for (int i = 1;i <= 2;i++) {
			if (x - i == R2 && y + i == C2)
				return false;
		}
	}
	if (dir == 6 || dir == 7) {
		for (int i = 1;i <= 2;i++) {
			if (x + i == R2 && y + i == C2)
				return false;
		}
	}
	return true;
}

int main() {
	cin >> R1 >> C1 >> R2 >> C2;

	queue<pair<int, int>> q;
	q.push({ R1,C1 });
	visit[R1][C1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == R2 && y == C2) {
			cout << visit[x][y]-1;
			return 0;
		}

		for (int i = 0;i < 8;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < 10 && ny >= 0 && ny < 9) {
				if (!visit[nx][ny]) {
					if (check(nx, ny, i)) {
						q.push({ nx,ny });
						visit[nx][ny] = visit[x][y] + 1;
					}
				}
			}
		}
	}

	cout << -1;
}