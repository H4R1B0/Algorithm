#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"
#define MAX 10010+1
#define INF 987654321
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int V, E;
int M, M_MAX;
int S, S_MAX;
vector<vector<pair<int, int>>> edge;
vector<int> house;
int dist[2][MAX];

void dijkstra(int start, int state) {
	for (int i = 0;i < V + 5;i++)
		dist[state][i] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[state][cur] < cost)
			continue;

		for (int i = 0;i < edge[cur].size();i++) {
			int next = edge[cur][i].first;
			int ncost = edge[cur][i].second + cost;

			if (state == 0 && ncost > M_MAX)
				continue;
			else if (state == 1 && ncost > S_MAX)
				continue;

			if (dist[state][next] > ncost) {
				dist[state][next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}	
}


int main(void) {
	cin >> V >> E;
	edge.resize(V + 5);
	house.resize(V + 5);

	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	cin >> M >> M_MAX;
	for (int i = 0;i < M;i++) {
		int a;
		cin >> a;
		edge[V + 1].push_back({a,0});
		house[a] = -1;
	}

	cin >> S >> S_MAX;
	for (int i = 0;i < S;i++) {
		int a;
		cin >> a;
		edge[V + 2].push_back({ a,0 });
		house[a] = -1;
	}

	dijkstra(V + 1, 0);
	dijkstra(V + 2, 1);

	int answer = INF;
	for (int i = 1;i <= V;i++) {
		if (house[i] == -1)
			continue;
		int sum = dist[0][i] + dist[1][i];
		answer = min(answer, sum);
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;
}
