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
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
vector<int> dist;
vector<pair<int, int>> v[MAX];
bool visit[MAX];

int bfs(int Start, int End) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ Start,0 });
	visit[Start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == End) {
			return cost;
		}

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;

			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,cost + ncost });
			}
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	dist.assign(N + 1, INF);
	for (int i = 0;i < N-1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b)<<endl;
	}
}