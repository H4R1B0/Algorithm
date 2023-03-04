#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000000+10
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
ll K;
ll stone[MAX];
int parent[MAX];

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
		parent[x] = y;
	else
		parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	vector<pair<ll, int>> v;
	for (int i = 1;i <= N;i++) {
		cin >> stone[i];
		parent[i] = i;
		v.push_back({ stone[i],i });
	}
	parent[1000001] = 1000001;
	set<pair<int, int>> s;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		s.insert({a,b});
	}
	for (int i = 1;i < N;i++) {
		int a = i;
		int b = i + 1;
		if (s.count({ a,b }) == 0) {
			if (Find(a) != Find(b)) {
				Union(a, b);
			}
		}
	}
	if (s.count({ 1,N }) == 0) {
		if (Find(1) != Find(N)) {
			Union(1, N);
		}
	}
	sort(v.begin(), v.end());
	ll total = 0;
	int cnt = 0;
	for (int i = 0;i < v.size();i++) {
		ll cost = v[i].first;
		int next = v[i].second;
		if (Find(1000001) != Find(next)) {
			Union(1000001, next);
			total += cost;
			cnt++;
		}
		if (cnt == s.size()) {
			break;
		}
	}
	if(M<=1) {
		cout << "YES";
		return 0;
	}
	if (cnt < s.size()) {
		cout << "NO";
		return 0;
	}
	if (K >= total) 
		cout << "YES";
	else
		cout << "NO";
}