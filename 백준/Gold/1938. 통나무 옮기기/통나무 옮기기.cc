#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int N, B_Shape, E_Shape;
char MAP[MAX][MAX];
bool Visit[MAX][MAX][2];

pair<int, int> Start[3], End[3], B_Center, E_Center;

int C_dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int C_dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int Check_Shape(pair<int, int> S[3]) {
	if (S[0].first == S[1].first && S[1].first == S[2].first)
		return 0;
	else
		return 1;
}

bool Change_Shape(int x, int y, int Shape) {
	if (Shape == 0) {
		for (int i = 0; i < 8; i++) {
			if (i == 3 || i == 4)
				continue;

			int nx = x + C_dx[i];
			int ny = y + C_dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
			if (MAP[nx][ny] == '1') return false;
		}
	}
	else if (Shape == 1) {
		for (int i = 0; i < 8; i++) {
			if (i == 1 || i == 6)
				continue;

			int nx = x + C_dx[i];
			int ny = y + C_dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				return false;
			if (MAP[nx][ny] == '1')
				return false;
		}
	}
	return true;
}

int BFS(int a, int b) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(a, b), make_pair(B_Shape, 0)));
	Visit[a][b][B_Shape] = true;

	while (!q.empty()) {
		bool F = false;

		int x = q.front().first.first;
		int y = q.front().first.second;
		int S = q.front().second.first;
		int Cnt = q.front().second.second;
		q.pop();

		if (x == E_Center.first && y == E_Center.second && S == E_Shape) {
			return Cnt;
		}

		if (S == 0) {
			int nx = x - 1;
			int ny = y;
			// Up
			if (nx >= 0 && ny - 1 >= 0 && ny + 1 < N && Visit[nx][ny][S] == false) {
				if (MAP[nx][ny] == '0' && MAP[nx][ny - 1] == '0' && MAP[nx][ny + 1] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			nx = x + 1;
			ny = y;
			// Down
			if (nx < N && ny - 1 >= 0 && ny + 1 < N && Visit[nx][ny][S] == false) {
				if (MAP[nx][ny] == '0' && MAP[nx][ny - 1] == '0' && MAP[nx][ny + 1] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			nx = x;
			ny = y - 1;
			// Left
			if (ny - 1 >= 0 && Visit[nx][ny][S] == false) {
				if (MAP[nx][ny - 1] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			nx = x;
			ny = y + 1;
			// Right
			if (ny + 1 < N && Visit[nx][ny][S] == false) {
				if (MAP[nx][ny + 1] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			// Turn
			if (Change_Shape(x, y, S) == true && Visit[x][y][1] == false) {
				Visit[x][y][1] = true;
				q.push({ { x,y }, { 1,Cnt + 1 } });
			}
		}
		else {
			int nx = x - 1;
			int ny = y;
			// Up
			if (nx - 1 >= 0 && Visit[nx][ny][S] == false) {
				if (MAP[nx - 1][ny] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			nx = x + 1;
			ny = y;
			// Down
			if (nx + 1 < N && Visit[nx][ny][S] == false) {
				if (MAP[nx + 1][ny] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			nx = x;
			ny = y - 1;
			// Left
			if (ny >= 0 && nx - 1 >= 0 && nx + 1 < N && Visit[nx][ny][S] == false) {
				if (MAP[nx][ny] == '0' && MAP[nx - 1][ny] == '0' && MAP[nx + 1][ny] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			nx = x;
			ny = y + 1;
			// Right
			if (ny < N && nx - 1 >= 0 && nx + 1 < N && Visit[nx][ny][S] == false) {
				if (MAP[nx][ny] == '0' && MAP[nx - 1][ny] == '0' && MAP[nx + 1][ny] == '0') {
					Visit[nx][ny][S] = true;
					q.push({ {nx,ny}, {S,Cnt + 1} });
				}
			}

			// Turn
			if (Change_Shape(x, y, S) == true && Visit[x][y][0] == false) {
				Visit[x][y][0] = true;
				q.push({ { x,y }, { 0,Cnt + 1 } });
			}
		}
	}
	return 0;
}

int main(void)
{
	cin >> N;
	int S_Idx = 0;
	int E_Idx = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'B') {
				Start[S_Idx++] = { i,j };

				MAP[i][j] = '0';
			}
			else if (MAP[i][j] == 'E') {
				End[E_Idx++] = { i,j };

				MAP[i][j] = '0';
			}
		}
	}
	B_Center = Start[1];
	E_Center = End[1];

	B_Shape = Check_Shape(Start);
	E_Shape = Check_Shape(End);

	int R = BFS(B_Center.first, B_Center.second);
	cout << R << endl;

	return 0;
}