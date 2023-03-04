#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int xd[] = { -2,-1,1,2,2,1,-1,-2 };
int yd[] = { 1,2,2,1,-1,-2,-2,-1 };

int N, M;
int g[MAX][MAX];
vector<int> ans;

void Solution(pair<int,int> a) {
	vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a.first,a.second},0 });
	visit[a.first][a.second] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (g[x][y]!=0) {
			ans[g[x][y]] = cnt;
		}

		for (int i = 0;i < 8;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx,ny},cnt + 1 });
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair<int, int> Start;
	cin >> N >> M;
	ans.resize(M + 1, 0);
	cin >> Start.first >> Start.second;
	int idx = 1;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = idx++;		
	}
	Solution(Start);
	for (int i = 1;i < ans.size();i++) {
		cout << ans[i] << " ";
	}
}