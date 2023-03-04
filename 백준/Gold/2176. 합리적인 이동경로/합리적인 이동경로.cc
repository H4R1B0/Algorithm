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
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
vector<pair<int, int>> v[MAX];
int dp[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	vector<int> dist(N + 1, INF);		
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,2 });
	dist[2] = 0;
	dp[2] = 1;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = cost + v[cur][i].second;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}

			if (cost > dist[next])
				dp[cur] += dp[next];
		}
	}
	cout << dp[1];
}