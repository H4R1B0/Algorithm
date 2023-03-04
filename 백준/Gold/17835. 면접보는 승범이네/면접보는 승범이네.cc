#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 10000000000
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
vector<int> pos;
vector<pair<int, int>> v[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[b].push_back({ a,c });
	}
	vector<ll> dist(N + 1, INF);
	dist[0] = 0;
	priority_queue<pair<ll, int>> pq;
	for (int i = 0;i < K;i++) {
		int a;
		cin >> a;
		dist[a] = 0;
		pq.push({ 0,a });
	}
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			ll ncost = v[cur][i].second + cost;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	//cout << dist.size();
	vector < pair<int, ll >> ans;
	ll Max = 0;
	for (int i = 1;i < dist.size();i++) {
		Max = max(Max, dist[i]);
		ans.push_back({ i,dist[i] });
	}
	sort(ans.begin(), ans.end());
	for (int i = 0;i < ans.size();i++) {
		int cur = ans[i].first;
		ll cost = ans[i].second;

		if (Max == cost) {
			cout << cur << endl << cost;
			return 0;
		}
	}
}