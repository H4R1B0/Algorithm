#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX][4];
pair<pair<int, int>, int> Start, End;

int turn_right(int d) {
	if (d == 0)
		return 2;
	else if (d == 1)
		return 3;
	else if (d == 2)
		return 1;
	else
		return 0;
}

int turn_left(int d) {
	if (d == 0)
		return 3;
	else if (d == 1)
		return 2;
	else if (d == 2)
		return 0;
	else
		return 1;
}
void bfs() {
	//x,y,방향,cnt
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {Start.first.first,Start.first.second}, {Start.second,0} });
	visit[Start.first.first][Start.first.second][Start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == End.first.first && y == End.first.second && dir == End.second) {
			//cout << x << y << dir << endl;
			cout << cnt;
			return;
		}

		for (int i = 1;i <= 3;i++) {
			int nx = x + xd[dir] * i;
			int ny = y + yd[dir] * i;

			if (map[nx][ny])
				break;
			if (nx < 1 || nx > N || ny < 1 || ny > M || visit[nx][ny][dir])
				continue;
			visit[nx][ny][dir] = true;
			q.push({ {nx,ny}, {dir,cnt + 1} });
		}

		int ndir = turn_left(dir);
		if (!visit[x][y][ndir]) {
			visit[x][y][ndir] = true;
			q.push({ {x,y}, {ndir,cnt + 1} });
		}

		ndir = turn_right(dir);
		if (!visit[x][y][ndir]) {
			visit[x][y][ndir] = true;
			q.push({ {x,y}, {ndir,cnt + 1} });
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= M;j++)
			cin >> map[i][j];
	int a, b, c;

	cin >> a >> b >> c;
	c -= 1;
	Start = { {a,b},c };

	cin >> a >> b >> c;
	c -= 1;
	End = { {a,b},c };
	bfs();
}