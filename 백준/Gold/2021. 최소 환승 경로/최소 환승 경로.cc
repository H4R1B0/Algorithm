#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, L;
int Start, End;
vector<int> v[MAX];
vector<int> dist(MAX,INF);

int bfs() {
	queue<int> q;
	q.push(Start);
	dist[Start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == End) {
			return dist[cur] - 1 > 0 ? dist[cur] - 1 : 0;
		}
		for (auto next : v[cur]) {
			if (dist[next] != INF)
				continue;
			if (next > 100000)
				dist[next] = dist[cur] + 1;
			else
				dist[next] = dist[cur];
			q.push(next);
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 1;i <= L;i++) {
		while (true) {
			int a;
			cin >> a;
			if (a == -1)
				break;
			v[a].push_back(i + 100000);
			v[i + 100000].push_back(a);
		}
	}
	cin >> Start >> End;
	cout<<bfs();
}