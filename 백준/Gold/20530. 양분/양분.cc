#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, Q;
int parent[MAX];
int Entry[MAX];
vector<int> v[MAX];
bool visit[MAX];
vector<bool> cycle(MAX, true);
vector<bool> group(MAX, true);

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

void dfs(int cur, int prev) {
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];
		if (cycle[next] || next == prev)
			continue;
		Union(cur, next);
		dfs(next, cur);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	for (int i = 1;i <= N;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		Entry[a]++;
		Entry[b]++;
	}

	queue<int> q;
	for (int i = 1;i <= N;i++) {
		if (Entry[i] == 1)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		visit[cur] = true;
		cycle[cur] = false;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			Entry[next]--;

			if (!visit[next] && Entry[next] == 1) {
				q.push(next);
			}
		}
	}	

	for (int i = 1;i <= N;i++) {
		if (Entry[i]) {
			dfs(i, -1);
		}
	}

	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b))
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
}