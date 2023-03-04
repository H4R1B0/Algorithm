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
#define MAX 25+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, T, D;
int map[MAX][MAX];
int dist_go[MAX][MAX];
int dist_back[MAX][MAX];

int cir_go(int x, int y, int nx, int ny) {
	int diff = map[nx][ny] - map[x][y];
	if (diff > 0)
		return diff * diff;
	else return 1;
}

int cir_back(int x, int y, int nx, int ny) {
	int diff = map[nx][ny] - map[x][y];
	if (diff < 0)
		return diff * diff;
	else return 1;
}

void dijkstra_go() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			dist_go[i][j] = INF;
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });
	dist_go[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (dist_go[x][y] != cost)
			continue;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (abs(map[nx][ny] - map[x][y]) > T)
				continue;
			if (dist_go[nx][ny] > cost + cir_go(x, y, nx, ny)) {
				dist_go[nx][ny] = cost + cir_go(x, y, nx, ny);
				pq.push({ -dist_go[nx][ny],{nx,ny} });
			}
		}
	}
}

void dijkstra_back() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			dist_back[i][j] = INF;
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });
	dist_back[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (dist_back[x][y] != cost)
			continue;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (abs(map[nx][ny] - map[x][y]) > T)
				continue;
			if (dist_back[nx][ny] > cost + cir_back(x, y, nx, ny)) {
				dist_back[nx][ny] = cost + cir_back(x, y, nx, ny);
				pq.push({ -dist_back[nx][ny],{nx,ny} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T >> D;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char c;
			cin >> c;
			if (c >= 'A' && c <= 'Z') {
				map[i][j] = c - 'A';
			}
			else if (c >= 'a' && c <= 'z') {
				map[i][j] = c - 'a' + 26;
			}
		}
	}

	dijkstra_go();
	dijkstra_back();
	int ans = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (dist_go[i][j] + dist_back[i][j] <= D)
				ans = max(ans, map[i][j]);
		}
	}
	cout << ans;
}