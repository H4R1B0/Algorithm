#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K;
int parent[100001];
int map[MAX][MAX];
queue<pair<int, int>> union_q;
queue<pair<int, int>> bfs_q;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

void bfs(){
	while (!bfs_q.empty())	{
		int x = bfs_q.front().first;
		int y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N || map[nx][ny] != 0)
				continue;

			map[nx][ny] = map[x][y];
			union_q.push({ nx, ny });

		}
	}
}

void Union_civil() {
	while (!union_q.empty()) {
		int x = union_q.front().first;
		int y = union_q.front().second;
		bfs_q.push({ x,y });
		union_q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx<1 || nx>N || ny<1 || ny>N || map[nx][ny] == 0)
				continue;
			if (map[x][y] == map[nx][ny] || Find(map[x][y]) == Find(map[nx][ny]))
				continue;

			Union(map[x][y], map[nx][ny]);
			K--;
		}
	}
}

int Solve() {
	int cnt = 0;

	while (K > 1) {
		Union_civil();
		
		if (K == 1)
			return cnt;

		bfs();
		cnt++;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0;i < K;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = i + 1;
		union_q.push({ a,b });
	}
	for (int i = 0;i < 100001;i++)
		parent[i] = i;

	cout<< Solve();
}