#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
//#define INF 10000000000
#define ll long long

//int xd[] = { 0,1 };
//int yd[] = { 1,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];
pair<int, int> Start, End;

void changeCost(int x, int y) {
	map[x][y] = 5000;
	for (int i = 0; i < 4; i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!map[nx][ny])
				map[nx][ny] = 1;
		}
	}
}

int main() {
	memset(dist, -1, sizeof(dist));
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char c;
			cin >> c;
			if (c == 'S') {
				Start = { i,j };
				map[i][j] = -1;
			}				
			if (c == 'F') {
				End = { i,j };
				map[i][j] = -1;
			}
			if (c == 'g') {
				changeCost(i, j);
			}
		}
	}

	map[Start.first][Start.second] = map[End.first][End.second] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{Start.first,Start.second} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (dist[x][y] != -1)
			continue;
		dist[x][y] = cost;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (dist[nx][ny] == -1) {
					int ncost = cost + map[nx][ny];
					pq.push({ -ncost,{nx,ny} });
				}
			}
		}
	}

	cout << dist[End.first][End.second]/5000 <<" "<< dist[End.first][End.second] % 5000;
}