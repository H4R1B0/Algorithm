#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 600+1

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start;

int bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ Start.first,Start.second });
	visit[Start.first][Start.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && map[nx][ny] != 'X') {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					if (map[nx][ny] == 'P')
						cnt++;
				}
			}
		}
	}
	return cnt;
}


int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I')
				Start = { i,j };
		}
	}
	int ans = bfs();
	if (ans == 0)
		cout << "TT";
	else
		cout << ans;
}