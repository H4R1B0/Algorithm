#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321987
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
bool map[MAX][MAX];
vector<pair<int, int>> v[MAX][MAX];
bool visit[MAX][MAX];

int bfs() {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visit[1][1] = true;
	map[1][1] = true;	

	while (!q.empty()) {
		bool flag = false;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y]) {
			for (int i = 0;i < v[x][y].size();i++) {
				int a = v[x][y][i].first;
				int b = v[x][y][i].second;
				if (!map[a][b]) {
					map[a][b] = true;
					cnt++;
					flag = true;
				}
			}
		}
		if (flag) {
			memset(visit, false, sizeof(visit));
			visit[x][y] = true;
			while (!q.empty())
				q.pop();
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
				if (!visit[nx][ny] && map[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b });
	}
	cout << bfs();
}