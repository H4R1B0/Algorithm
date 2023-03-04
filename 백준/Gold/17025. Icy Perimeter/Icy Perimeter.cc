#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1002+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N;
int arr[MAX][MAX];
char g[MAX][MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> ans;

int cal(int x, int y) {
	int cnt = 0;
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];
		if (g[nx][ny] == '.')
			cnt++;
	}
	return cnt;
}

void bfs(int a, int b) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	vector<pair<int, int>> v;
	q.push({ a,b });
	v.push_back({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		arr[x][y] = cal(x, y);

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
				if (!visit[nx][ny] && g[nx][ny] == '#') {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					v.push_back({ nx,ny });
					cnt++;
				}					
			}
		}
	}

	int sum = 0;
	for (int i = 0;i < v.size();i++) {
		int x = v[i].first;
		int y = v[i].second;
		sum += arr[x][y];
	}

	ans.push_back({ cnt,sum });
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		if (a.second < b.second) {
			return a.second < b.second;
		}
	}
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i <= N+1;i++) {
		for (int j = 0;j <= N+1;j++) {
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
				g[i][j] = '.';
		}
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> g[i][j];
		}
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (g[i][j] == '#' && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}

	//ans.push_back({ 13,21 });
	sort(ans.begin(), ans.end(),cmp);
	cout << ans[0].first << " " << ans[0].second;
}