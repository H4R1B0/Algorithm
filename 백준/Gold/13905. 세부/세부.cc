#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N, M, K;
int Start, End;
int parent[MAX];
vector<pair<pair<int, int>, int>> v;
vector<pair<int, int>> graph[MAX];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second > b.second;
}

int Find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

void bfs() {
	vector<bool> visit(N + 1, false);
	vector<int> cost(N + 1, INF);

	queue<int> q;
	q.push(Start);
	visit[Start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < graph[cur].size();i++) {
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;

			if (!visit[next]) {
				visit[next] = true;
				cost[next] = min(cost[cur], ncost);
				q.push(next);
			}
		}
	}

	if (cost[End] == INF)
		cout << 0;
	else
		cout << cost[End];
}

int main() {
	cin >> N >> M;

	for (int i = 1;i <= N;i++)
		parent[i] = i;

	cin >> Start >> End;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	sort(v.begin(), v.end(),cmp);
	
	for (int i = 0;i < v.size();i++) {
		if (Find(v[i].first.first) != Find(v[i].first.second)) {

			//cout << v[i].second.first << " " << v[i].second.second << endl;
			Union(v[i].first.first, v[i].first.second);

			graph[v[i].first.first].push_back({ v[i].first.second, v[i].second });
			graph[v[i].first.second].push_back({ v[i].first.first, v[i].second });
		}
	}

	bfs();
}