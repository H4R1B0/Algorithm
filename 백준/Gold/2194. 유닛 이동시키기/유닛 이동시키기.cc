#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>

#define endl "\n"
#define MAX 500+1
#define INF INT_MAX
#define ll long long
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, A, B, K;
int map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start, End;

bool check(int x, int y, int dir) {
	if (x<1 || x + A - 1>N || y<1 || y + B - 1>M)
		return false;

	if (dir == 0) {
		for (int i = x;i < x + A;i++) {
			if (map[i][y + B - 1] == -1)
				return false;
		}
	}
	else if (dir == 1) {
		for (int i = x;i < x + A;i++) {
			if (map[i][y] == -1)
				return false;
		}
	}
	else if (dir == 2) {
		for (int i = y;i < y + B;i++) {
			if (map[x + A - 1][i] == -1)
				return false;
		}
	}
	else if (dir == 3) {
		for (int i = y;i < y + B;i++) {
			if (map[x][i] == -1)
				return false;
		}
	}
	return true;
}

int bfs(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == End.first && y == End.second)
			return cnt;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (check(nx,ny,i) && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> N >> M >> A >> B >> K;
	for (int i = 0;i < K;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = -1;
	}

	cin >> Start.first >> Start.second;
	cin >> End.first >> End.second;
	cout << bfs(Start.first, Start.second);
}
