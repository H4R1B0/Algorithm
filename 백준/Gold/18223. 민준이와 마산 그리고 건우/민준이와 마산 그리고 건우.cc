#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>

#define endl "\n"
#define MAX 5000+1
#define INF 987654321
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int V, E, P;
vector<pair<int, int>> v[MAX];

int dijkstra(int Start, int End) {
	vector<int> dist(V + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,Start });
	dist[Start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second + cost;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	return dist[End];
}


int main(void) {
	cin >> V >> E >> P;
	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	if (dijkstra(1, V) >= dijkstra(1, P) + dijkstra(P, V)) {
		cout << "SAVE HIM";
	}
	else {
		cout << "GOOD BYE";
	}
}
