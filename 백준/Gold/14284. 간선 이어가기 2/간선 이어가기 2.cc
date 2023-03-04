#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 5000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int N, M, S, T;
int dist[MAX];
vector<pair<int, int>> v[MAX];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		dist[i] = INF;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> S >> T;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,S });
	dist[S] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second + cost;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}

	cout << dist[T];
}