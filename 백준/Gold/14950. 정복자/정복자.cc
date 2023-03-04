#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, T;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[y] = x;
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	int cnt = 0, sum=0;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (Find(x) != Find(y)) {
			Union(x, y);
			cnt++;
			sum += cost;
		}
	}
	cout << sum + T * cnt * (cnt - 1) / 2;
}