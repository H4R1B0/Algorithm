#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int TC, N, M, W;
int dist[MAX];
vector<pair<pair<int,int>,int>> map;

void Solve() {
	dist[1] = 0;
	for (int i = 1;i <= N - 1;i++) {
		for (int j = 0;j < map.size();j++) {
			int from = map[j].first.first;
			int to = map[j].first.second;
			int cost = map[j].second;

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int i = 0;i < map.size();i++) {
		int from = map[i].first.first;
		int to = map[i].first.second;
		int cost = map[i].second;

		if (dist[to] > dist[from] + cost) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(void)
{
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;

		map.clear();
		
		memset(dist, -1, sizeof(dist));
		
		for (int i = 0;i < M;i++) {
			int S, E, T;
			cin >> S >> E >> T;
			map.push_back({ {S,E},T });
			map.push_back({ {E,S},T });
		}
		for (int i = 0;i < W;i++) {
			int S, E, T;
			cin >> S >> E >> T;
			map.push_back({ {S,E},-T });
		}

		Solve();
	}
}