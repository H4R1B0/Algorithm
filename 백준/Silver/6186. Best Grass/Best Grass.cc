#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
char g[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && g[nx][ny] == '#') {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> g[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (g[i][j] == '#' && !visit[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}
