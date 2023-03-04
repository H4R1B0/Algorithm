#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M, R;
int result;
int map[MAX];
vector<pair<int, int>> g[MAX];

void bfs(int start) {
	int cnt = 0;
	vector<int> d(N+1, INF);
	queue<int> q;
	d[start] = 0;
	q.push(start);
	
	while (!q.empty()) {
		int cur = q.front();
		int dist = d[cur];
		q.pop();

		for (int i = 0;i < g[cur].size();i++) {
			int next = g[cur][i].first;
			int ndist = g[cur][i].second;

			if (d[next] > dist + ndist) {
				d[next] = dist + ndist;
				q.push(next);
			}
		}
	}

	for (int i = 1;i <= N;i++)
		if (d[i] <= M)
			cnt += map[i];
	result = max(result, cnt);
}

int main(void)
{
	cin >> N >> M >> R;
	for (int i = 1;i <= N;i++) {
		cin >> map[i];
	}
	for (int i = 0;i < R;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	for (int i = 1;i <= N;i++) {
		bfs(i);
	}
	cout << result;
}