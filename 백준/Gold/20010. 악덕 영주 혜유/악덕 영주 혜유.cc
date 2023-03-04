#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };
int odd_xd[] = { 0,-1,0,1,1,-1 };
int odd_yd[] = { 1,0,-1,0,1,1 };
int even_xd[] = { 0,-1,0,1,1,-1 };
int even_yd[] = { 1,0,-1,0,-1,-1 };

int N, K;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;
vector<pair<int, int>> v2[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

ll dfs(int cur, int before) {
	ll ret = 0;
	for (int i = 0;i < v2[cur].size();i++) {
		int next = v2[cur][i].first;
		int cost = v2[cur][i].second;

		if (next == before)
			continue;
		ret = max(ret, dfs(next, cur) + cost);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0;i < N;i++)
		parent[i] = i;
	for (int i = 0;i < K;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	ll total = 0;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int from = v[i].second.first;
		int to = v[i].second.second;

		if (Find(from) != Find(to)) {
			total += cost;
			Union(from, to);
			v2[from].push_back({ to,cost });
			v2[to].push_back({ from,cost });
		}
	}
	
	ll ans = 0;
	for (int i = 0;i < N;i++) {
		ans = max(ans, dfs(i, -1));
	}
	cout << total << endl << ans;
}