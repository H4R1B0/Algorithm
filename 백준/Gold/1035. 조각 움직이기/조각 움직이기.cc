#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 5+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int result = INF;
vector<pair<int, int>> v;
char map[MAX][MAX];
bool visit[MAX][MAX];

int calc(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

void check(int x, int y) {
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			if (map[nx][ny] == '*' && !visit[nx][ny]) {
				visit[nx][ny] = true;
				check(nx, ny);
			}
		}
	}
}

bool connect() {
	int cnt = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (map[i][j] == '*' && !visit[i][j]) {
				visit[i][j] = true;
				cnt++;
				check(i, j);
			}
		}
	}

	if (cnt == 1)
		return true;
	return false;
}

void dfs(int cnt, int dist) {
	if (dist >= result)
		return;

	if (cnt == v.size()) {
		if (connect()) {
			result = min(result, dist);
		}
		return;
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (map[i][j] == '.') {
				map[i][j] = '*';
				dfs(cnt + 1, dist + calc(v[cnt].first, v[cnt].second, i, j));
				map[i][j] = '.';
			}
		}
	}
}


int main() {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				v.push_back({ i,j });
				map[i][j] = '.';
			}
		}
	}
	dfs(0, 0);
	cout << result;
}