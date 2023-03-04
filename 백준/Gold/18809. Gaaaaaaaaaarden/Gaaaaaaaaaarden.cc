#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, G, R;
int result;
int map[MAX][MAX];
bool Selected[11];
vector<pair<int, int>> Land;
vector<int> Green, Red;
vector<vector<pair<int,int>>> map2;

int bfs() {
	int cnt = 0;
	map2.clear();
	map2.assign(N, vector<pair<int, int>>(M, {-1,-1}));
	queue<pair<int, int>> q;
	for (auto p : Green) {
		int x = Land[p].first;
		int y = Land[p].second;
		map2[x][y] = { 0,0 };
		q.push({ x,y });
	}
	for (auto p : Red) {
		int x = Land[p].first;
		int y = Land[p].second;
		map2[x][y] = { 1,0 };
		q.push({ x,y });
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int color = map2[x][y].first;
		int ctime = map2[x][y].second;
		q.pop();

		if (map2[x][y].first == 100)
			continue;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 0)
				continue;
			if (map2[nx][ny].first == -1) {
				map2[nx][ny].first = color;
				map2[nx][ny].second = ctime + 1;
				q.push({ nx,ny });
			}
			else if (map2[nx][ny].first != 100) {
				if (map2[nx][ny].first != color && map2[nx][ny].second == ctime + 1) {
					map2[nx][ny].first = 100;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

void Select(int idx, int gcnt,int rcnt) {
	if (gcnt + rcnt > Land.size())
		return;
	if (gcnt > G)
		return;
	if (rcnt > R)
		return;
	if (gcnt == G && rcnt == R)
		result = max(result, bfs());

	for (int i = idx;i < Land.size();i++) {
		if (Selected[i])
			continue;
		Selected[i] = true;
		Green.push_back(i);
		Select(i, gcnt + 1, rcnt);
		Green.pop_back();
		Red.push_back(i);
		Select(i, gcnt, rcnt + 1);
		Red.pop_back();
		Selected[i] = false;
	}
}

int main() {
	cin >> N >> M >> G >> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				Land.push_back({ i,j });
		}
	}
	Select(0, 0, 0);
	cout << result;
}