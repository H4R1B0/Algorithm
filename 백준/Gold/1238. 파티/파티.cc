#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, X;
int dist[MAX], result[MAX];
vector<pair<int, int>> v[MAX];


void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;

			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
}


int main() {
	cin >> N >> M >> X;
	for (int i = 0;i < M;i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			dist[j] = INF;
		}
		dijkstra(i);
		result[i] = dist[X];
	}

	for (int j = 1;j <= N;j++) {
		dist[j] = INF;
	}
	dijkstra(X);
	for (int j = 1;j <= N;j++) {
		result[j] += dist[j];
	}
	sort(result + 1, result + N + 1);
	cout << result[N];
}