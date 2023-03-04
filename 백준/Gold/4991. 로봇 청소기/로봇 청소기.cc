#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 20+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;

int map[MAX][MAX];
bool visit[MAX][MAX][1<<10];
pair<int, int> Start;

int bfs(int a, int b, int t) {
	//x,y,durtytotal,cnt
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {a,b}, {0,0} });
	visit[a][b][0] = false;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int total = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (total == (1 << t) - 1)
			return cnt;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			int ntotal = total;
			int ncnt = cnt + 1;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == -1)
				continue;

			if (map[nx][ny] > 0) {
				ntotal = ntotal | (1 << (map[nx][ny] - 1));
			}
				
			if (!visit[nx][ny][ntotal]) {
				q.push({ {nx,ny}, {ntotal,ncnt} });
				visit[nx][ny][ntotal] = true;
			}
		}
	}
	return -1;
}

int main() {
	while (1) {
		cin >> M >> N;
		if (N == 0 && M == 0)
			break;

		memset(map, -1, sizeof(map));
		int durty_total = 0;
		string str;
		for (int i = 0;i < N;i++) {
			cin >> str;
			for (int j = 0;j < M;j++) {
				if (str[j] == 'o') {
					Start = { i,j };
					map[i][j] = 0;
				}
				else if (str[j] == '*')
					map[i][j] = ++durty_total;
				else if (str[j] == 'x')
					map[i][j] = -1;
				else
					map[i][j] = 0;
			}
		}

		cout << bfs(Start.first, Start.second, durty_total) << endl;
	}
}