#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
char map[MAX][MAX];
int visit[MAX][MAX][4];
pair<int, int> Start, End;

pair<int, int> Change_Direct(int Cur_Dir)
{
	pair<int, int> R;
	if (Cur_Dir == 0 || Cur_Dir == 1)
	{
		R.first = 2;
		R.second = 3;
	}
	else if (Cur_Dir == 2 || Cur_Dir == 3)
	{
		R.first = 0;
		R.second = 1;
	}
	return R;
}

void bfs() {
	//x,y,dir,cnt
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0;i < 4;i++) {
		visit[Start.first][Start.second][i]=0;
		q.push({ {Start.first,Start.second},i });
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		int nx = x + xd[dir];
		int ny = y + yd[dir];
		pair<int, int> ndir = Change_Direct(dir);

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (map[nx][ny] == '*')
			continue;
		else if (map[nx][ny] == '!') {
			if (visit[nx][ny][dir] > visit[x][y][dir]) {
				visit[nx][ny][dir] = visit[x][y][dir];
				q.push({ {nx,ny},dir });
			}
			if (visit[nx][ny][ndir.first] > visit[x][y][dir] + 1) {
				visit[nx][ny][ndir.first] = visit[x][y][dir] + 1;
				q.push({ {nx,ny},ndir.first });
			}
			if (visit[nx][ny][ndir.second] > visit[x][y][dir] + 1) {
				visit[nx][ny][ndir.second] = visit[x][y][dir] + 1;
				q.push({ {nx,ny},ndir.second });
			}
		}
		else if (map[nx][ny] == '.') {
			if (visit[nx][ny][dir] > visit[x][y][dir]) {
				visit[nx][ny][dir] = visit[x][y][dir];
				q.push({ {nx,ny},dir });
			}
		}
		else if (map[nx][ny] == '#') {
			if (visit[nx][ny][dir] > visit[x][y][dir]) {
				visit[nx][ny][dir] = visit[x][y][dir];
			}
		}
	}
}

int main() {
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == '#')
				v.push_back({ i,j });
			visit[i][j][0] = visit[i][j][1] = visit[i][j][2] = visit[i][j][3] = INF;
		}
	}
	Start = v[0];
	End = v[1];

	bfs();
	int result = INF;
	for (int i = 0;i < 4;i++) {
		result = min(result, visit[End.first][End.second][i]);
	}
	cout << result;
}