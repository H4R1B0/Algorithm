#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N, P, K;
int dist[MAX];
vector<pair<int, int>> v[MAX];

bool dijkstra(int x) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int next = i.first;
			int ncost = cost + (i.second > x);
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	return (dist[N] <= K);
}

int main() {
	cin >> N >> P >> K;
	for (int i = 0;i < P;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int ans = -1;
	int left = 0, right = 1e6;
	while (left <= right) {
		int mid = (left + right) /2;
		if (dijkstra(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
}