#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 126
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int map[MAX][MAX];
int dist[MAX][MAX];

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -map[0][0],{0,0} });
	dist[0][0] = map[0][0];

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				int ncost = cost + map[nx][ny];
				if (dist[nx][ny] > ncost) {
					dist[nx][ny] = ncost;
					pq.push({ -dist[nx][ny],{nx,ny} });
				}
			}
		}
	}
}

int main() {
	int idx = 1;
	while (true) {
		cin >> N;
		if (!N)
			break;

		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				cin >> map[i][j];

		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				dist[i][j] = INF;

		dijkstra();
		cout << "Problem "<<idx++ <<": " << dist[N - 1][N - 1] << endl;
	}
}