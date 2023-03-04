#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 20001
#define RED 1
#define BLUE 2


int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int K,V,E;
vector<int> map[MAX];
int visit[MAX];
bool result;

void bfs(int start) {
	queue<int> q;
	int color = RED;
	visit[start] = color;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visit[cur] == RED)
			color = BLUE;
		else if (visit[cur] == BLUE)
			color = RED;

		int mapsize = map[cur].size();
		for (int i = 0;i < mapsize;i++) {
			int next = map[cur][i];
			if (!visit[next]) {
				visit[next] = color;
				q.push(next);
			}
		}
	}
}

bool checkmap() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			int next = map[i][j];
			if (visit[i] == visit[next]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	cin >> K;
	for (int t = 0;t < K;t++) {
		cin >> V >> E;
		for (int i = 0;i < E;i++) {
			int u, v;
			cin >> u >> v;
			map[u].push_back(v);
			map[v].push_back(u);
		}

		for (int i = 1;i <= V;i++) {
			if (!visit[i])
				bfs(i);
		}
		if (checkmap()) {
			cout << "YES"<<endl;
		}
		else {
			cout << "NO" << endl;
		}
		for (int i = 0; i <= V; i++) {
			map[i].clear();
		}
		memset(visit, false, sizeof(visit));
	}
}