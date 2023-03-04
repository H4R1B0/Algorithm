#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int N, M;
int dist[MAX];
vector<pair<int, int >> v[MAX];

void dijkstra(int start) {
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ dist[start],start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (dist[cur] < distance)
			continue;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int nextDistance = distance + v[cur][i].second;

			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ -nextDistance,next });
				
			}
		}

	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	int s, e;
	cin >> s >> e;
	
	dijkstra(s);

	cout << dist[e];
}