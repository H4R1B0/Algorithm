#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
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

void Init() {
	for (int i = 1;i <= N;i++)
		parent[i] = i;
}

vector<pair<int, pair<int, int>>> GetVector(int idx) {
	vector<pair<int, pair<int, int>>> nv;
	for (int i = idx;i < v.size();i++) {
		nv.push_back(v[i]);
	}
	return nv;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ i,{a,b} });
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < K;i++) {
		vector<pair<int, pair<int, int>>> list = GetVector(i);
		Init();
		int total = 0;
		int cnt = 0;
		for (auto l : list) {
			int cost = l.first;
			int from = l.second.first;
			int to = l.second.second;
			if (Find(from) != Find(to)) {
				Union(from, to);
				cnt++;
				total += cost;
			}
		}
		if (cnt == N-1)
			cout << total << " ";
		else
			cout << 0 << ' ';
	}
}