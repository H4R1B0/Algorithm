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
#define MAX 4000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int dist_wolf[MAX][2];
int dist_fox[MAX];
vector<pair<int, int>> v[MAX];

void dijkstra_fox() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	dist_fox[1] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second * 2;

			if (dist_fox[next] > dist_fox[cur] + ncost) {
				dist_fox[next] = dist_fox[cur] + ncost;
				pq.push({ -dist_fox[next],next });
			}
		}
	}
}

void dijkstra_wolf() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{1,1} });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second.first;
		int state = pq.top().second.second;
		pq.pop();

		if (dist_wolf[cur][!state] < cost)
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost;

			if (state) {
				ncost = cost + v[cur][i].second;
			}
			else {
				ncost = cost + v[cur][i].second * 4;
			}

			if (dist_wolf[next][state] > ncost) {
				dist_wolf[next][state] = ncost;
				pq.push({ -ncost, {next, !state} });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		dist_wolf[i][0] = dist_wolf[i][1] = dist_fox[i] = INF;

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dijkstra_fox();
	dijkstra_wolf();

	int cnt = 0;
	for (int i = 2;i <= N;i++) {
		//cout << i << " " << dist_fox[i] << " " << min(dist_wolf[i][0], dist_wolf[i][1]) << endl;
		if (dist_fox[i] < min(dist_wolf[i][0], dist_wolf[i][1]))
			cnt++;
	}
	cout << cnt;
}