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
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int cnt = 1;
int visit[MAX][MAX];
char map[MAX][MAX];


int dfs(int x, int y) {
	if (visit[x][y] != -1)
		return visit[x][y];

	int ret = visit[x][y];
	visit[x][y] = cnt;
	int dir=0;
	if (map[x][y] == 'R')
		dir = 0;
	else if (map[x][y] == 'L')
		dir = 1;
	else if (map[x][y] == 'D')
		dir = 2;
	else if (map[x][y] == 'U')
		dir = 3;

	int nx = x + xd[dir];
	int ny = y + yd[dir];

	ret = dfs(nx, ny);
	visit[x][y] = ret;
	return visit[x][y];
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (visit[i][j] == -1) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	set<int> s;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			s.insert(visit[i][j]);
		}
	}
	cout << s.size();
}