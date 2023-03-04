#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 11

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int result=987654321;
char map[MAX][MAX];
pair<int, int> Red, Blue;

int inverse_dir(int dir) {
	if (dir == 0 || dir == 1)
		return 1 - dir;
	if (dir == 2 || dir == 3)
		return 5 - dir;
}

int move_dis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void Move(int rx, int ry, int bx, int by,int cnt, int dir) {
	if (cnt >= result)
		return;
	if (cnt > 10)
		return;

	bool red_flag = false;
	bool blue_flag = false;

	int nrx = rx + xd[dir];
	int nry = ry + yd[dir];
	while (1) {
		if (map[nrx][nry] == '#') {
			break;
		}
		if (map[nrx][nry] == 'O') {
			red_flag = true;
			break;
		}
		nrx += xd[dir];
		nry += yd[dir];
	}
	nrx -= xd[dir];
	nry -= yd[dir];

	int nbx = bx + xd[dir];
	int nby = by + yd[dir];
	while (1) {
		if (map[nbx][nby] == '#') {
			break;
		}
		if (map[nbx][nby] == 'O') {
			blue_flag = true;
			break;
		}
		nbx += xd[dir];
		nby += yd[dir];
	}
	nbx -= xd[dir];
	nby -= yd[dir];

	if (blue_flag == true) {
		return;
	}
	else if (red_flag == true) {
		result = min(result, cnt);
		return;
	}

	if (nrx == nbx && nry == nby) {
		int red_dis = move_dis(rx, ry, nrx, nry);
		int blue_dis = move_dis(bx, by, nbx, nby);

		if (red_dis > blue_dis) {
			nrx -= xd[dir];
			nry -= yd[dir];
		}
		else{
			nbx -= xd[dir];
			nby -= yd[dir];
		}
	}

	for (int i = 0;i < 4;i++) {
		if (i == dir || i == inverse_dir(dir))
			continue;
		Move(nrx, nry, nbx, nby, cnt + 1, i);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				Red.first = i;
				Red.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				Blue.first = i;
				Blue.second = j;
				map[i][j] = '.';
			}
		}
	}

	for (int i = 0;i < 4;i++) {
		Move(Red.first, Red.second, Blue.first, Blue.second, 1, i);
	}
	

	if (result > 10 || result == 987654321)
		result = -1;
	cout << result;
}