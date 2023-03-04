#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];

void dijkstra() {
	//cost, 좌표
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });
	dist[0][0] = 0;

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
			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				pq.push({ -dist[nx][ny],{nx, ny} });
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = MAX * MAX;
		}
	}

	dijkstra();
	cout << dist[N - 1][M - 1];
}