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
#define MAX 50+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N,M;
int parent[251];
char map[MAX][MAX];
int K_map[MAX][MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> K_v;
vector<pair<int, pair<int,int>>> Edge;
pair<int, int> Start;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[y] = x;
}

bool bfs(int Sx, int Sy, int Ex, int Ey, int node1, int node2) {
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {Sx,Sy},0 });
	visit[Sx][Sy] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == Ex && y == Ey) {
			Edge.push_back({ cnt,{node1,node2} });
			return true;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] == '1')
					continue;
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx,ny},cnt + 1 });
				}
			}
		}
	}
	return false;
}

int main() {
	int K_cnt = 1;
	cin >> N>>M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				Start = { i,j };
			}
			else if(map[i][j]=='K') {
				K_v.push_back({ i,j });
				K_map[i][j] = K_cnt++;
			}
		}
	}

	//서로 간 거리 계산
	for (int i = 0;i < K_v.size();i++) {
		int x = K_v[i].first;
		int y = K_v[i].second;

		bool flag = bfs(Start.first, Start.second, x, y, 0, K_map[x][y]);
		if (flag == false) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0;i < K_v.size();i++) {
		int x = K_v[i].first;
		int y = K_v[i].second;

		for (int j = i + 1;j < K_v.size();j++) {
			int xx = K_v[j].first;
			int yy = K_v[j].second;

			bool flag = bfs(x, y, xx, yy, K_map[x][y], K_map[xx][yy]);
			if (flag == false) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for (int i = 0;i < K_cnt;i++)
		parent[i] = i;
	sort(Edge.begin(), Edge.end());
	int result = 0;
	for (int i = 0;i < Edge.size();i++) {
		int cost = Edge[i].first;
		int from = Edge[i].second.first;
		int to = Edge[i].second.second;

		if (Find(from) != Find(to)) {
			Union(from, to);
			result += cost;
		}
	}
	cout << result;
}