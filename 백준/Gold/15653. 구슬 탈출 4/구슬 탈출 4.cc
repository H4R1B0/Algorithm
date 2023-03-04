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
#define MAX 10+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
pair<int, int> Red, Blue;

struct INFO{
	int rx, ry;
	int bx, by;
	int cnt;
};

int inverse_dir(int dir) {
	if (dir == 0 || dir == 1)
		return 1 - dir;
	if (dir == 2 || dir == 3)
		return 5 - dir;
}

int move_dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void bfs() {
	queue<INFO> q;
	q.push({ Red.first, Red.second, Blue.first, Blue.second, 0 });
	visit[Red.first][Red.second][Blue.first][Blue.second];
	
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0;i < 4;i++) {
			bool red_flag = false;
			bool blue_flag = false;

			int nrx = rx + xd[i];
			int nry = ry + yd[i];
			while (1) {
				if (map[nrx][nry] == '#')
					break;
				if (map[nrx][nry] == 'O') {
					red_flag = true;
					break;
				}
				nrx += xd[i];
				nry += yd[i];
			}
			nrx -= xd[i];
			nry -= yd[i];

			int nbx = bx + xd[i];
			int nby = by + yd[i];
			while (1) {
				if (map[nbx][nby] == '#')
					break;
				if (map[nbx][nby] == 'O') {
					blue_flag = true;
					break;
				}
				nbx += xd[i];
				nby += yd[i];
			}
			nbx -= xd[i];
			nby -= yd[i];

			if (blue_flag == true)
				continue;
			else if (red_flag == true) {
				cout << cnt + 1;
				return;
			}

			if (nrx == nbx && nry == nby) {
				int red_dist = move_dist(rx, ry, nrx, nry);
				int blue_dist = move_dist(bx, by, nbx, nby);

				if (red_dist > blue_dist) {
					nrx -= xd[i];
					nry -= yd[i];
				}
				else {
					nbx -= xd[i];
					nby -= yd[i];
				}
			}
			if (!visit[nrx][nry][nbx][nby]) {
				visit[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby,cnt + 1 });
			}
		}
	}
	cout << -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];

			if (map[i][j] == 'R') {
				Red = { i,j };
				map[i][j] = '.';
			}
				
			else if (map[i][j] == 'B') {
				Blue = { i,j };
				map[i][j] = '.';
			}
		}
	}
	bfs();
}