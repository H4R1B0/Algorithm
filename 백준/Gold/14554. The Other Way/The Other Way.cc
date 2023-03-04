#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, S, E;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> S >> E;
	vector<vector<pair<int, int>>> v(N + 1);
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	vector<ll> dist(N + 1, numeric_limits<ll>::max());
	vector<int> DP(N + 1, 0);
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0,S });
	dist[S] = 0;
	DP[S] = 1;
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;
		if (cur == E)
			continue;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			ll ncost = cost + (ll)v[cur][i].second;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				DP[next] = DP[cur];
				pq.push({ -ncost,next });
			}
			else if (dist[next] == ncost) {
				DP[next] = (DP[next] + DP[cur]) % 1000000009;
			}
		}
	}
	cout << DP[E];
}