#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int parent[MAX];
vector<int> computer[MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;

	if (x > y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	cnt = M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int a;
			cin >> a;
			if (i == j)
				continue;
			if (i == 1 || j == 1)
				continue;

			v.push_back({ a,{i,j} });
		}
	}
	sort(v.begin(), v.end());

	int total = 0;
	vector<pair<int, int>> ans;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (Find(x) != Find(y)) {
			Union(x, y);
			ans.push_back({ x,y });
			total += cost;
			cnt++;
		}
	}
	cout << total << " " << ans.size() << endl;
	for (auto a : ans) {
		cout << a.first << " " << a.second << endl;
	}
}