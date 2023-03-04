#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, answer, ans;
int Start[3];
vector<pair<int, int>> v[MAX];
int dist[3][MAX];
int node[3][MAX];

void dijkstra(int idx, int start) {
	dist[idx][start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[idx][cur] < cost)
			continue;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (dist[idx][next] > ncost + cost) {
				dist[idx][next] = ncost + cost;
				node[idx][next] = cur;
				pq.push({ -dist[idx][next],next });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dist, 0x3f, sizeof(dist));
	answer = INF;

	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0;i < 3;i++) {
		cin >> Start[i];
		dijkstra(i, Start[i]);
	}

	for (int i = 1;i <= N;i++) {
		int sum = 0;
		for (int j = 0;j < 3;j++) {
			sum += dist[j][i];
		}
		if (answer > sum) {
			ans = i;
			answer = sum;
		}
	}

	int cnt = 0;
	for (int i = 0;i < 3;i++) {
		int a = ans;
		while (a != Start[i]) {
			a = node[i][a];
			cnt++;
		}
	}
	cout << answer << " " << cnt << endl;
	for (int i = 0;i < 3;i++) {
		int a = ans;
		while (a != Start[i]) {
			cout << a << " " << node[i][a] << endl;
			a = node[i][a];
		}
	}
}