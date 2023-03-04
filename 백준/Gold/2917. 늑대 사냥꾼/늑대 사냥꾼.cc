#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
char MAP[MAX][MAX];
int dist[MAX][MAX];
pair<int, int> Start, End;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dist, -1, sizeof(dist));
	cin >> N >> M;

	queue<pair<int, int>> tree;
	priority_queue<pair<int, pair<int, pair<int, int>>>> pq;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == '+') {
				dist[i][j] = 0;
				tree.push({ i,j });
			}				
			else if (MAP[i][j] == 'V')
				Start = { i,j };				
			else if (MAP[i][j] == 'J')
				End = { i,j };
		}
	}

	while (!tree.empty()) {
		int x = tree.front().first;
		int y = tree.front().second;
		tree.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny]==-1) {
				dist[nx][ny] = dist[x][y] + 1;
				tree.push({ nx,ny });
			}
		}
	}

	pq.push({ dist[Start.first][Start.second],{dist[Start.first][Start.second],{Start.first,Start.second}} });
	while (!pq.empty()) {
		int x = pq.top().second.second.first;
		int y = pq.top().second.second.second;
		int distance = pq.top().first;
		int minDistansce = pq.top().second.first;
		pq.pop();

		//cout << x << " " << y <<" "<< distance <<" "<<minDistansce<< endl;
		if (x == End.first && y == End.second) {
			cout << minDistansce;
			return 0;
		}

		if (dist[x][y] == -1)
			continue;

		dist[x][y] = -1;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny] != -1) {
				pq.push({ dist[nx][ny],{min(minDistansce,dist[nx][ny]),{nx,ny}} });
			}
		}
	}
}