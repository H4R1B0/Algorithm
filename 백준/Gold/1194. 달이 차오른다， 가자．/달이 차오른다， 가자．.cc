#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX][1<<6];

pair<int, int> Start;
vector<pair<int,int>> End;

bool check(int key, int door) {
	int value = key & (1 << (int(door) - 'A'));
	if (value != 0)
		return true;
	return false;
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	queue<pair<int, int>> door[26];
	q.push({ {Start.first, Start.second},{0,0} });
	visit[Start.first][Start.second][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int key = q.front().second.second;
		q.pop();

		if (map[x][y] == '1') {
			cout << cnt << endl;
			return;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[nx][ny][key]) {
				if (map[nx][ny] == '.' || map[nx][ny] == '1') {
					visit[nx][ny][key] = true;
					q.push({ {nx,ny}, {cnt + 1,key} });
				}
				else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
					int tmp = key | (1 << (int(map[nx][ny] - 'a')));
					visit[nx][ny][tmp] = true;
					q.push({ {nx,ny}, {cnt + 1,tmp} });
				}
				else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
					if (check(key, map[nx][ny])) {
						visit[nx][ny][key] = true;
						q.push({ {nx,ny}, {cnt + 1,key} });
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				Start = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == '1') {
				End.push_back({ i,j });
			}
		}
	}

	bfs();
}