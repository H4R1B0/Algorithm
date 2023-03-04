#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 300+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, Q;
vector<vector<int>> g;
pair<int, int> v[MAX];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	g.resize(N + 1, vector<int>(N + 1, INF));
	for (int i = 1;i <= N;i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
		g[i][i] = 0;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == j)
				continue;
			if ((v[i].first <= v[j].first && v[j].first <= v[i].second) || (v[i].first <= v[j].second && v[j].second <= v[i].second)) {
				g[i][j] = 1;
				g[j][i] = 1;
			}
		}
	}

	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	cin >> Q;
	for (int i = 0;i < Q;i++) {
		int a, b;
		cin >> a >> b;
		if (g[a][b] == INF)
			cout << -1 << endl;
		else
			cout << g[a][b] << endl;
	}
}