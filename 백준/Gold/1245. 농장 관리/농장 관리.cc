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

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
bool flag;
int map[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int x, int y) {
	for (int i = 0;i < 8;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (map[nx][ny] > map[x][y])
				flag = false;
			if (!visit[nx][ny] && map[nx][ny] == map[x][y]) {
				visit[nx][ny] = true;
				dfs(nx, ny);
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
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!visit[i][j]) {
				flag = true;
				dfs(i, j);
				if (flag)
					ans++;
			}
		}
	}

	cout << ans;
}