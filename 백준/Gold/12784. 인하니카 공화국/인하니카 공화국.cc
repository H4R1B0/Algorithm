#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<pair<int, int>> v[MAX];
bool visit[MAX];

int dfs(int cur, int before) {
	int ret = 0, beforeWeight = 0;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i].first;
		int cost = v[cur][i].second;

		if (next == before) {
			beforeWeight = cost;
			continue;
		}
		ret += dfs(next, cur);
	}

	if (v[cur].size() == 1)
		return beforeWeight;

	return min(ret, beforeWeight);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(visit, false, sizeof(visit));
		for (int i = 1;i <= N;i++)
			v[i].clear();
		for (int i = 0;i < M;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		int ans = 0;
		for (int i = 0;i < v[1].size();i++) {
			int next = v[1][i].first;
			ans += dfs(next, 1);
		}
		cout << ans << endl;
	}
}