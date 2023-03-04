#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, C;
int parent[MAX];
vector<pair<int, int>> pos;
vector<pair<ll,pair<int,int>>> v;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y)
		parent[y] = x;
	else
		parent[x] = y;
}

ll cal(int x, int y, int xx, int yy) {
	return (xx - x) * (xx - x) + (yy - y) * (yy - y);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;
	for (int i = 0;i < MAX;i++)
		parent[i] = i;

	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		pos.push_back({ a,b });
	}

	for (int i = 0;i < pos.size();i++) {
		for (int j = i+1;j < pos.size();j++) {
			ll cost = cal(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
			if(cost >= C)
				v.push_back({ cost,{i,j} });
		}
	}
	sort(v.begin(), v.end());

	ll ans = 0;
	int cnt = 0;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (Find(x) != Find(y)) {
			ans += cost;
			cnt++;
			Union(x, y);
		}
	}
	if (cnt != N - 1)
		cout << -1;
	else
		cout << ans;
}