#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { -1,0,1,0 };
int yd[4] = { 0,1,0,-1 };

int N, M;
int MAP[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int x, int y, int dir, int cnt) {
	for (int i = 0;i < 4;i++) {
		int ndir = (dir + 3 - i) % 4;
		int nx = x + xd[ndir];
		int ny = y + yd[ndir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || MAP[nx][ny] == 1)
			continue;
		if (!visit[nx][ny] && MAP[nx][ny] == 0) {
			visit[nx][ny] = true;
			dfs(nx, ny, ndir, cnt + 1);
		}
	}

	int nx = x - xd[dir];
	int ny = y - yd[dir];
	if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
		if (MAP[nx][ny] == 0) {
			dfs(nx, ny, dir, cnt);
		}
		else {
			cout << cnt;
			exit(0);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> M;
	int s, e, d;
	cin >> s >> e >> d;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	visit[s][e] = true;
	dfs(s, e, d, 1);
}