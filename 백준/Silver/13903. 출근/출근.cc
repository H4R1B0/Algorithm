#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int R, C, N;
vector<pair<int, int>> dir;
int g[MAX][MAX];
bool visit[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	queue<pair<pair<int, int>, int>> q;

	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> g[i][j];
			if (i == 0 && g[i][j] == 1) {
				q.push({ {i,j},0 });
				visit[i][j] = true;
			}				
		}
	}
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		dir.push_back({ a,b });
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == R - 1) {
			cout << cnt;
			return 0;
		}

		for (int i = 0;i < dir.size();i++) {
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!visit[nx][ny] && g[nx][ny]==1) {
					q.push({ {nx,ny},cnt + 1 });
					visit[nx][ny] = true;
				}
			}
		}
	}
	cout << -1;
}