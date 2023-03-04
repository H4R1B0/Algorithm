#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>

#define endl "\n"
#define MAX 100000+1
#define INF LLONG_MAX
#define ll long long
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, D, E;
vector<int> height;
vector<pair<int, int>> v[MAX];

ll dijkstra() {
	vector<ll> dist1(N + 1, INF);
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		ll d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d > dist1[cur])
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			ll nd = v[cur][i].second + d;

			if (dist1[next] > nd && height[next] > height[cur]) {
				dist1[next] = nd;
				pq.push({ -nd,next });
			}
		}
	}

	vector<ll> dist2(N + 1, INF);
	pq.push({ 0,N });
	while (!pq.empty()) {
		ll d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d > dist2[cur])
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			ll nd = v[cur][i].second + d;

			if (dist2[next] > nd && height[next] > height[cur]) {
				dist2[next] = nd;
				pq.push({ -nd,next });
			}
		}
	}

	ll result = -INF;
	for (int i = 2;i < N;i++) {
		if (dist1[i] == INF || dist2[i] == INF)
			continue;
		result = max(result, height[i] * E - (dist1[i] + dist2[i]) * D);
	}
	return result;
}

int main(void) {
	cin >> N >> M >> D >> E;
	height.resize(N + 1);
	for (int i = 1;i <= N;i++) {
		cin >> height[i];
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	ll tmp = dijkstra();
	if (tmp == -INF)
		cout << "Impossible";
	else
		cout << tmp;
}
