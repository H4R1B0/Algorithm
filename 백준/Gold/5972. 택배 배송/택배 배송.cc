#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 50000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int dist[MAX];
vector<pair<int, int>> v[MAX];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;

			if (dist[next] > dist[cur] + ncost) {
				dist[next] = dist[cur] + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		dist[i] = INF;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dijkstra();
	cout << dist[N];
}