#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[8] = { 0,0,1,-1,1,1,-1,-1 };
int yd[8] = { 1,-1,0,0,1,-1,1,-1 };

int P,W,C,V;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x >= y)
		parent[x] = y;
	else
		parent[y] = x;
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first > b.first;
}

int main() {
	cin >> P >> W;
	for (int i = 0;i < P;i++)
		parent[i] = i;
	cin >> C >> V;
	for (int i = 0;i < W;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		Union(x, y);

		if (Find(C) == Find(V)) {
			cout << cost;
			return 0;
		}
	}
}