#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int R, C;
char map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start;
vector<pair<int, int>> Fire;

void bfs() {
	queue<pair<int, int>> q;
	q.push(Start);
	queue<pair<int, int>> flame;
	for (int i = 0;i < Fire.size();i++)
		flame.push(Fire[i]);

	int result = 0;
	while (!q.empty()) {

		int flamesize = flame.size();
		for (int i = 0;i < flamesize;i++) {
			int x = flame.front().first;
			int y = flame.front().second;
			flame.pop();

			for (int j = 0;j < 4;j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
					if (map[nx][ny] == '.' || map[nx][ny] == 'J') {
						map[nx][ny] = 'F';
						flame.push({ nx,ny });
					}
				}
			}
		}

		int qsize = q.size();
		for (int i = 0;i < qsize;i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
				cout << result+1;
				return;
			}

			for (int j = 0;j < 4;j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visit[nx][ny]) {
					if (map[nx][ny] == '.') {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		result++;
	}
	cout << "IMPOSSIBLE";
	return;
}

int main(void)
{
	cin >> R >> C;;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				Start.first = i;
				Start.second = j;
			}
			if (map[i][j] == 'F') {
				Fire.push_back({ i,j });
			}
		}
	}
	bfs();
}