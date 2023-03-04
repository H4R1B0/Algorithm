#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 1001
#define endl '\n'

int xd[] = { -1,0,1,0 };
int yd[] = { 0,1,0,-1 };
int MAP[MAX][MAX];

int main(void) {
	int C, R, K;
	cin >> C >> R;
	cin >> K;
	if (K > R * C) {
		cout << 0;
		return 0;
	}
	int cnt = 1;
	int x = R - 1, y = 0, dir = 0;
	while (cnt != K) {
		MAP[x][y] = cnt;
		int nx = x + xd[dir];
		int ny = y + yd[dir];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || MAP[nx][ny] != 0) {
			dir = (dir + 1) % 4;
			nx = x + xd[dir];
			ny = y + yd[dir];
		}
		x = nx;
		y = ny;
		cnt++;
	}
	cout << y + 1 << " " << R - x;
}