#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX 1501

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int R,C;
int cnt;
bool Find;

char map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q, nq, swan_q, swan_nq;
pair<int, int> swan_pos;

void swan_bfs() {
	while (!swan_q.empty() && !Find) {
		int x = swan_q.front().first;
		int y = swan_q.front().second;
		swan_q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!visit[nx][ny]) {
					if (map[nx][ny] == '.') {
						visit[nx][ny] = true;
						swan_q.push({ nx,ny });
					}
					if (map[nx][ny] == 'X') {
						visit[nx][ny] = true;
						swan_nq.push({ nx,ny });
					}
					if (map[nx][ny] == 'L') {
						visit[nx][ny] = true;
						Find = true;
						break;
					}
				}
			}
		}
	}
}

void water_bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (map[nx][ny] == 'X'){
					map[nx][ny] = '.';
					nq.push({nx,ny});
				}
			}
		}
	}
}

void solution() {
	int day = 0;

	swan_q.push({ swan_pos.first,swan_pos.second });
	visit[swan_pos.first][swan_pos.second] = true;

	while (!Find) {
		swan_bfs();

		if (!Find) {
			water_bfs();

			q = nq;
			swan_q = swan_nq;

			while (!nq.empty())
				nq.pop();
			while (!swan_nq.empty())
				swan_nq.pop();
			day++;
		}
	}
	cout << day;
}

int main() {
	Find = false;
	cin >> R >> C;

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];

			if (map[i][j] != 'X')
				q.push({ i,j });
			if (map[i][j] == 'L') {
				swan_pos = { i,j };
			}
		}
	}
	solution();
}