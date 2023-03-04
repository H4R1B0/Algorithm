#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int s, e;
int M;
int cnt;
int visit[MAX];
int dis[MAX];
vector<int> family[MAX];

void bfs() {
	queue<int> q;
	visit[s] = true;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		//cout << cur << " ";
		q.pop();

		for (int i = 0;i < family[cur].size();i++) {
			int next = family[cur][i];

			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
				dis[next] = dis[cur] + 1;
				if (next == e)
					return;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> s >> e;
	cin >> M;
	for (int i = 0;i < M;i++) {
		int x, y;
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);
	}
	bfs();

	if (dis[e] == 0)
		cout << -1;
	else
		cout << dis[e];
}