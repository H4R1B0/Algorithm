#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
int g[MAX][MAX];
vector<vector<int>> dist(MAX, vector<int>(MAX, INF));

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> g[i][j];
		}
	}

	if (N == 1) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });
	dist[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		dist[x][y] = cost;
		ans = max(ans, cost);
		if (x == N - 1 && y == N - 1)
			break;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				int ncost = abs(g[nx][ny] - g[x][y]);
				if (dist[nx][ny] > ncost) {
					dist[nx][ny] = ncost;
					pq.push({ -ncost,{nx,ny} });
				}
			}
		}
	}
	cout << ans;
}