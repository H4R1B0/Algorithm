#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 300+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

//int xd[8] = { -3,-2,2,3,3,2,-2,-3 };
//int yd[8] = { 2,3,3,2,-2,-3,-3,-2 };

int N, M, trash;
pair<int, int> Start, End;
char map[MAX][MAX];
char tmp[MAX][MAX];
bool visit[MAX][MAX];

bool bfs() {
	queue<pair<int, int>> q;
	q.push(Start);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visit[nx][ny]) {
				visit[nx][ny] = true;
				if (map[nx][ny] == '#') {
					return true;
				}
				if (map[nx][ny] == '1') {
					tmp[nx][ny] = '0';
					continue;
				}
				q.push({ nx,ny });
			}
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	cin >> trash >> trash >> trash >> trash;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> map[i][j];
			if (map[i][j] == '*')
				Start = { i,j };
			if (map[i][j] == '#')
				End = { i,j };
		}
	}

	int ans = 0;
	while (1) {
		ans++;
		memset(visit, false, sizeof(visit));
		memcpy(tmp, map, sizeof(tmp));
		if (bfs())
			break;
		memcpy(map, tmp, sizeof(tmp));
	}
	cout << ans;
}