#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<vector<int>> g;

int cal(int x, int y) {
	int distance = 0;
	for (int i = 1; i <= N; i++)
		distance += min(g[x][i], g[y][i]);
	return distance;
}

int main() {
	cin >> N >> M;
	g.resize(N + 1, vector<int>(N + 1, INF));
	for (int i = 1;i <= N;i++)
		g[i][i] = 0;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {				
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	int ax, ay, ans = INF;
	for (int i = 1;i <= N;i++) {
		for (int j = i + 1;j <= N;j++) {
			int ret = cal(i, j);
			if (ans > ret) {
				ax = i, ay = j;
				ans = ret;
			}
		}
	}

	cout << ax << " " << ay << " " << ans * 2;
}