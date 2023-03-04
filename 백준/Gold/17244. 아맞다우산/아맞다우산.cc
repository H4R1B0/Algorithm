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
#define MAX 50+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, Bit;
int Xtotal;
char map[MAX][MAX];
bool visit[MAX][MAX][1<<5];
pair<int, int> Start, End;

void bfs() {
	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {Start.first,Start.second},{0,0} });
	visit[Start.first][Start.second][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int Bit_State = q.front().second.second;
		q.pop();

		if (map[x][y] == 'E' && Bit_State == Bit) {
			cout << cnt;
			return;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			int nBit_State = Bit_State;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] >= '0' && map[nx][ny] < '5') {
					nBit_State = Bit_State | (1 << map[nx][ny] - '0');
					if (!visit[nx][ny][nBit_State]) {
						visit[nx][ny][nBit_State] = true;
						q.push({ {nx,ny}, {cnt + 1,nBit_State} });
					}
				}
				else if (map[nx][ny] != '#') {
					if (!visit[nx][ny][nBit_State]) {
						visit[nx][ny][nBit_State] = true;
						q.push({ {nx,ny}, {cnt + 1,nBit_State} });
					}
				}
			}
		}
	}
}

int main() {
	cin >> M >> N;

	int idx = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				Start = { i,j };
			}
			else if (map[i][j] == 'X') {
				map[i][j] = idx + '0';
				idx++;
			}
		}
	}
	Bit = (1 << idx) - 1;
	bfs();
}