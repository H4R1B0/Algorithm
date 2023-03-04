#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[6] = { -2,-2,0,0,2,2 };
int yd[6] = { -1,1,-2,2,-1,1 };

int N;
int map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start, End;

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {Start.first, Start.second},0 });
	visit[Start.first][Start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (x == End.first && y == End.second) {
			return cnt;
		}

		for (int i = 0;i < 6;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny]) {
				q.push({ {nx,ny},cnt + 1 });
				visit[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> N;
	cin >> Start.first >> Start.second >> End.first >> End.second;
	cout << bfs();
}