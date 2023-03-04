#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
vector<pair<int, int>> v[MAX];
int visit[MAX];
int dist[101][MAX];

void dijkstra() {
	int discovered = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur] >= K)
			continue;
		visit[cur]++;
		int cnt = visit[cur];
		dist[cnt][cur] = distance;
		if (cnt == K)
			discovered++;
		if (discovered == N)
			break;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			pq.push({ -dist[cnt][cur] - ncost, next });
		}
	}
}

int main(void)
{
	cin >> N >> M >> K;
	for (int i = 1;i <= K;i++) {
		for (int j = 1;j <= N;j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dijkstra();
	for (int i = 1;i <= N;i++) {
		if (dist[K][i] == INF)
			cout << -1 << endl;
		else
			cout << dist[K][i] << endl;
	}
}