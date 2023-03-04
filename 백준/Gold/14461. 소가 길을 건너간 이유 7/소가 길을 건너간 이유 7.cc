#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, T;
bool visit[MAX][MAX][3];
int arr[MAX][MAX];
int dist[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			dist[i][j] = INF;
		}
	}

	priority_queue<pair<int, pair<int,pair<int,int>>>> pq;
	pq.push({ 0,{0,{0,0}} });
	dist[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cnt = pq.top().second.first;
		int x = pq.top().second.second.first;
		int y = pq.top().second.second.second;
		pq.pop();

		if (visit[x][y][cnt % 3])
			continue;

		visit[x][y][cnt % 3] = true;
		dist[x][y] = min(dist[x][y], cost);
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				int ncost = cost + T;
				if (cnt % 3 == 2)
					ncost += arr[nx][ny];
				pq.push({ -ncost,{cnt + 1,{nx,ny}} });
			}
		}		
	}
	cout << dist[N - 1][N - 1];
}