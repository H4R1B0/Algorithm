#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 510
#define endl '\n'

int xd[] = { 0,1,0,-1 };
int yd[] = { -1,0,1,0 };

int xdx[4][10] = { { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
				   { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
				   { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },				   
				   { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };
int ydy[4][10] = { { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
				   { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
				   { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
				   {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} };
int percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };
int N;
int answer = 0;
int MAP[MAX][MAX];

void Spread_Sand(int x, int y, int dir) {
	int xx = x + xd[dir];
	int yy = y + yd[dir];
	if (MAP[xx][yy] == 0)
		return;
	int Sand = MAP[xx][yy];
	int tmp = Sand;
	for (int i = 0;i < 9;i++) {
		int nx = x + xdx[dir][i];
		int ny = y + ydy[dir][i];
		int plus = (tmp * percent[i]) / 100;
		if (nx<1 || nx>N || ny<1 || ny>N)
			answer += plus;
		else
			MAP[nx][ny] += plus;
		Sand -= plus;		
	}
	int nx = x + xdx[dir][9];
	int ny = y + ydy[dir][9];
	if (nx<1 || nx>N || ny<1 || ny>N)
		answer += Sand;
	else
		MAP[nx][ny] += Sand;
	MAP[x][y] = 0;
}

void Solution() {
	int x = (N + 1) / 2;
	int y = (N + 1) / 2;
	int dir = 0;
	int move_cnt = 1;
	
	while (1) {
		for (int i = 0;i < 2;i++) {
			for (int j = 0;j < move_cnt;j++) {
				Spread_Sand(x, y, dir);
				x += xd[dir];
				y += yd[dir];
			}
			dir = (dir + 1) % 4;
		}
		move_cnt++;

		if (move_cnt == N) {
			for (int j = 0;j < move_cnt;j++) {
				Spread_Sand(x, y, dir);
				x += xd[dir];
				y += yd[dir];
			}
			break;
		}
	}
	cout << answer;
}

int main(void) {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> MAP[i][j];
		}
	}
	
	Solution();
}