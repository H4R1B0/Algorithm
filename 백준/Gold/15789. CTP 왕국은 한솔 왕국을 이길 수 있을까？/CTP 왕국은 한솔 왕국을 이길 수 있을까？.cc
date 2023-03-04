#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int parent[MAX];
int cnt[MAX];
bool visit[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y) {
		parent[x] = y;
		cnt[y] += cnt[x];
	}		
	else {
		parent[y] = x;
		cnt[x] += cnt[y];
	}		
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		if (Find(a) != Find(b))
			Union(a, b);
	}

	int C, H, K;
	cin >> C >> H >> K;

	priority_queue<int> pq;
	for (int i = 1;i <= N;i++) {
		int tmp = Find(i);
		if (!visit[tmp] && tmp != parent[C] && tmp != parent[H]) {
			pq.push(cnt[tmp]);
			visit[tmp] = true;
		}
	}

	while (K--) {
		int tmp = pq.top();
		pq.pop();

		cnt[parent[C]] += tmp;
	}
	while (!pq.empty())
		pq.pop();
	cout << cnt[parent[C]];
}