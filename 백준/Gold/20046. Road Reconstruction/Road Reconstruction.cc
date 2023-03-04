#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];

int dijkstra() {
	vector<vector<int>> dist(N, vector<int>(M, INF));
	dist[0][0] = map[0][0];
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -dist[0][0],{0,0} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] == -1)
				continue;
			int ncost = cost + map[nx][ny];
			if (dist[nx][ny] > ncost) {
				dist[nx][ny] = ncost;
				pq.push({ -ncost,{nx,ny} });
			}

		}
	}
	return dist[N - 1][M - 1];
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}
	if (map[0][0] == -1 || map[N - 1][M - 1] == -1) {
		cout << -1;
		return 0;
	}
	int ans = dijkstra();
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
}