#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

//int xd[8] = { -3,-2,2,3,3,2,-2,-3 };
//int yd[8] = { 2,3,3,2,-2,-3,-3,-2 };

int N, M;
int Entry[MAX];
int before[MAX];
vector<int> dist;
vector<pair<int, int>> v[MAX];

void bfs() {
	queue<int> q;
	q.push(1);
	while (Entry[1]) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int cost = v[cur][i].second;

			Entry[next]--;
			if (dist[next] < dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				before[next] = cur;
			}
			if (Entry[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	cin >> N >> M;
	dist.resize(N + 1);
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		Entry[b]++;
	}

	bfs();

	vector<int> ans;
	cout << dist[1] << endl;
	int i = before[1];
	while (i != 1) {
		ans.push_back(i);
		i = before[i];
	}
	cout << 1 << " ";
	reverse(ans.begin(),ans.end());
	for (int x : ans) {
		cout << x << " ";
	}
	cout << 1 << " ";
}