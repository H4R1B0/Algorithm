#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, J, S;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> g(N + 1, vector<int>(N + 1,INF));
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	cin >> J >> S;

	int answer = -1;
	int Min = INF;
	for (int i = 1;i <= N;i++) {
		if (i == J || i == S)
			continue;
		if (Min > g[J][i] + g[S][i])
			Min = g[J][i] + g[S][i];
	}

	vector<int> ans;
	int Min_time = INF;
	for (int i = 1;i <= N;i++) {
		if (i == J || i == S)
			continue;
		if ((Min == g[J][i] + g[S][i]) && g[J][i] <= g[S][i] && Min_time > g[J][i]) {
			Min_time = g[J][i];
		}
	}

	for (int i = 1;i <= N;i++) {
		if (i == J || i == S)
			continue;
		if ((Min == g[J][i] + g[S][i]) && Min_time == g[J][i]) {
			ans.push_back(i);
		}
	}
	if (!ans.empty()) {
		sort(ans.begin(), ans.end());
		answer = ans[0];
	}
	cout << answer;
}