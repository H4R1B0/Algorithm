#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
int dist[MAX];
int parent[MAX];
vector<pair<int, int>> v[MAX];

void dijkstra(int start) {
	for (int i = 1;i <= N;i++)
		dist[i] = INF;
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
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
				parent[next] = cur;
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijkstra(1);
	cout << N - 1 << endl;
	for (int i = 2;i <= N;i++) {
		cout << parent[i] << " " << i << endl;
	}
}