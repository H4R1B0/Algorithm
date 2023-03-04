#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 105+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };
int odd_xd[] = { 0,-1,0,1,1,-1 };
int odd_yd[] = { 1,0,-1,0,1,1 };
int even_xd[] = { 0,-1,0,1,1,-1 };
int even_yd[] = { 1,0,-1,0,-1,-1 };

int N, M;
int g[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];
vector<vector<int>> tmp_g;

int cal(int x, int y) {
	if (x % 2 == 1) {
		int cnt = 0;
		for (int i = 0;i < 6;i++) {
			int nx = x + odd_xd[i];
			int ny = y + odd_yd[i];
			if (tmp_g[nx][ny] == 0)
				cnt++;
		}
		return cnt;
	}
	else {
		int cnt = 0;
		for (int i = 0;i < 6;i++) {
			int nx = x + even_xd[i];
			int ny = y + even_yd[i];
			if (tmp_g[nx][ny] == 0)
				cnt++;
		}
		return cnt;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	tmp_g.resize(N + 2, vector<int>(M + 2, 1));
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> g[i][j];
		}
	}
	//vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	tmp_g[0][0] = 0;
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 6;i++) {
			int nx, ny;
			if (x % 2 == 1) {
				nx = x + odd_xd[i];
				ny = y + odd_yd[i];
			}
			else {
				nx = x + even_xd[i];
				ny = y + even_yd[i];
			}

			if (nx >= 0 && nx <= N + 1 && ny >= 0 && ny <= M + 1) {
				if (!visit[nx][ny] && g[nx][ny] == 0) {
					visit[nx][ny] = true;
					tmp_g[nx][ny] = 0;
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (tmp_g[i][j] == 1)
				dist[i][j] = cal(i, j);
		}
	}

	int sum = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			sum += dist[i][j];
		}
	}
	cout << sum;
}