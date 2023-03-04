#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 110+1

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int R, C, N;
string map[MAX];
bool visit[MAX][MAX];

pair<int, int> getLocation(int turn, int high) {
	pair<int, int> p = { high,-1 };
	if (turn % 2 == 1) {
		p.second = 0;
		while (p.second < C && map[p.first][p.second] == '.')
			p.second++;
	}
	else {
		p.second = C - 1;
		while (p.second >= 0 && map[p.first][p.second] == '.')
			p.second--;
	}
	return p;
}

bool checkMap() {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	visit[R][0] = true;
	q.push({ R,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx <= R && ny >= 0 && ny < C) {
				if (!visit[nx][ny] && map[nx][ny] == 'x') {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
	}

	for (int i = 0;i < R;i++)
		for (int j = 0;j < C;j++)
			if (map[i][j] == 'x' && !visit[i][j])
				return true;
	return false;
}

void gravity() {
	int Min = R;

	for (int j = 0; j < C; j++) {
		for (int i = R; i > 0; i--) {
			if (map[i][j] != 'x' || !visit[i][j])
				continue;

			int h = 0;

			for (int k = i - 1; k >= 0; k--) {
				if (map[k][j] == 'x') {
					if (!visit[k][j])
						Min = min(Min, h);
					break;
				}
				else
					h++;
			}
		}
	}
	//cout << Min << endl;
	for (int j = 0;j < C;j++)
		for (int i = R - 1; i >= 0; i--)
			if (!visit[i][j] && map[i][j] == 'x') {
				map[i + Min][j] = 'x';
				map[i][j] = '.';
			}

	return;
}

int main() {
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		cin >> map[i];
	}
	for (int i = 0;i < C;i++)
		map[R].push_back('x');

	cin >> N;
	for (int n = 1;n <= N;n++) {
		int h;
		cin >> h;
		pair<int, int> loc = getLocation(n, R - h);
		//cout << loc.first << " " << loc.second << endl;
		if (loc.second >= 0 && loc.second < C)
			map[loc.first][loc.second] = '.';

		if (checkMap())
			gravity();
			
	}
	for (int i = 0;i < R;i++)
		cout << map[i] << endl;
}