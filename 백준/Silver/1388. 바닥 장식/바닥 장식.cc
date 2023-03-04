#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == 1) {
			for (int i = 0;i < 2;i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (!visit[nx][ny] && map[nx][ny]==map[x][y]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		else {
			for (int i = 2;i < 4;i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (!visit[nx][ny] && map[nx][ny] == map[x][y]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char c;
			cin >> c;
			if (c == '-') {
				map[i][j] = 1;
			}
			if (c == '|') {
				map[i][j] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!visit[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}
