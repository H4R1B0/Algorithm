#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x,int y) {
	x = Find(x);
	y = Find(y);

	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll sum = 0;
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		sum += c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	ll total = 0;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;
		if (Find(x) != Find(y)) {
			Union(x, y);
			total += cost;
			cnt++;
		}
	}
	if (cnt != N - 1) {
		cout << -1;
		return 0;
	}
	else {
		cout << sum - total;
	}
}