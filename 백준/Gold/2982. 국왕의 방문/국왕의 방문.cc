#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int A, B, K, G;
int time_table[MAX][MAX];
vector<int> G_list;
pair<int, int> G_table[MAX][MAX];
vector<pair<int, int>> v[MAX];
vector<int> dist;
bool visit[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> A >> B >> K >> G;
	for (int i = 0;i < G;i++) {
		int a;
		cin >> a;
		G_list.push_back(a);
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		time_table[a][b] = c;
		time_table[b][a] = c;
	}

	int start = 0;
	for (int i = 0;i < G_list.size() - 1;i++) {
		int a, b;
		a = G_list[i];
		b = G_list[i + 1];
		G_table[a][b] = { start,start + time_table[a][b] };
		G_table[b][a] = { start,start + time_table[a][b] };
		start += time_table[a][b];
	}
	dist.resize(N + 1, INF);
	dist[A] = K;
	priority_queue<pair<int, int>> pq;
	pq.push({ -K,A });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur])
			continue;
		visit[cur] = true;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			pair<int, int> T = G_table[cur][next];
			if (cost >= T.first && cost <= T.second) {
				ncost += T.second - cost;
			}
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
	cout << dist[B] - K;
}