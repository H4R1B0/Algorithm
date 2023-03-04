#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
vector<vector<pair<pair<int, int>, int>>> map;
vector<vector<int>> dist;

int dijkstra(int start) {
	priority_queue<pair<pair<int, int>, int>> pq;
	dist[start][0] = 0;
	pq.push({ {0,0},start });

	while (!pq.empty()) {
		int curDist = -pq.top().first.first;
		int curCost = -pq.top().first.second;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur][curCost] < curDist)
			continue;
		if (curCost > M)
			continue;
		if (cur == N)
			return curDist;

		for (int i = 0;i < map[cur].size();i++) {			
			int nextDist = map[cur][i].first.first + curDist;
			int nextCost = map[cur][i].first.second + curCost;
			int next = map[cur][i].second;

			if (nextCost > M)
				continue;
			if (nextDist < dist[next][nextCost]) {
				for (int j = nextCost + 1;j <= M;j++) {
					if (dist[next][j] <= nextDist)
						break;
					dist[next][j] = nextDist;
				}

				dist[next][nextCost] = nextDist;
				pq.push({ {-nextDist,-nextCost},next });
			}
		}
	}
	return -1;
}

int main(void)
{
	int Tc;
	cin >> Tc;
	while (Tc--) {
		cin >> N >> M >> K;
		map.assign(N + 1, vector<pair<pair<int, int>, int>>());
		dist.assign(N + 1, vector<int>(M + 1, INF));
		for (int i = 0;i < K;i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			map[u].push_back({ {d,c},v });
		}
		int result = dijkstra(1);
		if (result == -1) {
			cout << "Poor KCM\n";
		}
		else {
			cout << result << '\n';
		}
	}
}