#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M,A,B, C;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> A >> B >> C;
	vector<vector<pair<int, int>>> v(N + 1);
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	priority_queue<pair<int, pair<int,int>>> pq;
	pq.push({ 0,{0,A} });
	vector<int> dist(N + 1, INF);
	dist[A] = 0;
	while (!pq.empty()) {
		int min_cost = -pq.top().first;
		int cost = pq.top().second.first;
		int cur = pq.top().second.second;
		pq.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int nmin_cost = max(v[cur][i].second, min_cost);
			int ncost = cost + v[cur][i].second;

			if (dist[next] > nmin_cost && ncost<=C) {
				dist[next] = nmin_cost;
				pq.push({ -nmin_cost,{ncost,next} });
			}
		}
	}
	if (dist[B] == INF)
		cout << -1;
	else
		cout << dist[B];
}