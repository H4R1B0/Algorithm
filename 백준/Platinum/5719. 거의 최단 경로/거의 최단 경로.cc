#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, S, D;
vector<vector<pair<int, int>>> g;
vector<vector<int>> prv;
bool check[MAX][MAX];

int dijkstra() {
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> pq;
	prv = vector<vector<int>>(N + 1);

	pq.push({ 0, S });
	dist[S] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;		
		pq.pop();

		if (cost > dist[cur])continue;

		for(int i=0;i<g[cur].size();i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;

			if (check[cur][next])
				continue;

			if (dist[next] == dist[cur] + ncost) {
				prv[next].push_back(cur);
			}

			if (dist[next] > dist[cur] + ncost) {
				prv[next].clear();
				prv[next].push_back(cur);
				dist[next] = dist[cur] + ncost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	if (dist[D] == INF)
		return -1;
	else
		return dist[D];
}

void erase(int cur) {
	for (int i = 0;i < prv[cur].size();i++) {
		int next = prv[cur][i];
		for (int j = 0; j < g[next].size(); j++) {
			if (g[next][j].first == cur && !check[next][cur]) {
				check[next][cur] = true;
				erase(next);
				break;
			}
		}
	}
}

int main() {
	while (1) {
		g.clear(); prv.clear();

		cin >> N >> M;

		if (!N && !M)
			break;

		memset(check, false, sizeof(check));

		cin >> S >> D;
		g = vector<vector<pair<int, int>>>(N + 1);

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back({ b, c });
		}
		dijkstra();
		erase(D);
		cout << dijkstra() << endl;
	}
	return 0;
}