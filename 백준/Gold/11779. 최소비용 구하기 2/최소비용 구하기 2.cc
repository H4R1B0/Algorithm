#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int Start, End;
int dist[MAX];
int route[MAX];
vector<pair<int, int>> v[MAX];
vector<int> route_v;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,Start });
	dist[Start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;

			if (dist[next] > cost + ncost) {
				route[next] = cur;
				dist[next] = cost + ncost;
				pq.push({ -dist[next],next });
			}
		}

	}

	cout << dist[End] << endl;
	int tmp = End;
	while (tmp) {
		route_v.push_back(tmp);
		tmp = route[tmp];
	}
	cout << route_v.size() << endl;
	for (int i = route_v.size() - 1;i >= 0;i--)
		cout << route_v[i] << " ";
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		dist[i] = INF;
	}

	for (int i = 1;i <= M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> Start >> End;

	dijkstra();
}