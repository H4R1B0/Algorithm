#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, ans;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;
vector<int> result;

int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;
	parent[y] = x;
}

bool Same_parent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else
		return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 0;i < v.size();i++) {
		if (!Same_parent(v[i].second.first, v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			result.push_back(v[i].first);
		}
	}

	for (int i = 0;i < result.size()-1;i++)
		ans += result[i];
	cout << ans;
}