#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int map[MAX][MAX];
int visit[MAX][MAX];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] == 1) {
					if (visit[nx][ny] > visit[x][y]) {
						visit[nx][ny] = visit[x][y];
						q.push({ nx,ny });
					}
				}
				else {
					if (visit[nx][ny] > visit[x][y] + 1) {
						visit[nx][ny] = visit[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < N;j++) {
			map[i][j] = str[j] - '0';
		}
	}
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			visit[i][j] = INF;
		}
	}
	bfs();
	cout << visit[N - 1][N - 1];
}