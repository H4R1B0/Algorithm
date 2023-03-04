#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100000+1

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int V, E;
int visit[MAX];
int cnt;
vector<int> v[MAX];
set<pair<int, int>> result;
int dfs(int cur, int cur_before) {
	cnt++;
	visit[cur] = cnt;
	int ret = visit[cur];
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];
		if (next == cur_before)
			continue;
		if (visit[next]) {
			ret = min(ret, visit[next]);
			continue;
		}

		int prev = dfs(next, cur);
		if (prev > visit[cur]) {
			int a = min(cur, next);
			int b = max(cur, next);
			if (!result.count({ a,b }))
				result.insert({ a,b });
		}
		ret = min(ret, prev);
	}
	return ret;
}

int main() {
	cin >> V >> E;
	for (int i = 1;i <= E;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1;i <= V;i++) {
		if (!visit[i])
			dfs(i, 0);
	}

	cout << result.size() << endl;
	for (auto x : result)
		cout << x.first << ' ' << x.second << endl;
}