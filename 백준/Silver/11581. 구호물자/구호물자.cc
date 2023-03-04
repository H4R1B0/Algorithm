#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
int g[MAX][MAX];
vector<int> v[MAX];
int visit[MAX];

void dfs(int cur) {
	if (visit[cur] == 1) {
		cout << "CYCLE";
		exit(0);
	}
	visit[cur] = 1;
	for (auto i : v[cur]) {
		if (visit[i] != 2)
			dfs(i);
	}
	visit[cur] = 2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N - 1;i++) {
		cin >> M;
		for (int j = 0;j < M;j++) {
			int a;
			cin >> a;
			//v[i].push_back(a);
			g[i][a] = 1;
		}
	}
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (g[i][k] && g[k][j])
					g[i][j] = 1;
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		if (g[1][i] && g[i][i] == 1) {
			cout << "CYCLE";
			return 0;
		}
	}
	cout << "NO CYCLE";
}