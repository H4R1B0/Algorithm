#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 300+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
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

	if (x != y) {
		parent[y] = x;
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++) {
		int cost;
		cin >> cost;
		v.push_back({ cost,{0,i} });
		parent[i] = i;
	}
		
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int a;
			cin >> a;
			if (i == j)
				continue;
			v.push_back({ a,{i,j} });
		}
	}
	sort(v.begin(), v.end());

	int ans=0;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (Find(x) != Find(y)) {
			Union(x, y);
			ans += cost;
		}
	}
	cout << ans;
}