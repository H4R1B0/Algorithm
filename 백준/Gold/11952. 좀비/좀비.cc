#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 10000000000
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K, S;
ll P, Q;
vector<bool> Zombie;
vector<ll> Cost;
vector<vector<int>> v;

void bfs(int X) {
	vector<bool> visit(N + 1,false);
	queue<pair<int, ll> > q;
	visit[X] = true;
	Cost[X] = 0;
	q.push(make_pair(X, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		ll cnt = q.front().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visit[next] && (cnt + 1 <= S) && (!Zombie[next])) {
				visit[next] = true;
				Cost[next] = Q;
				q.push(make_pair(next, cnt + 1));
			}
		}
	};
}

int main() {
	cin >> N >> M >> K >> S;
	cin >> P >> Q;
	Zombie.resize(N + 1, false);
	Cost.resize(N + 1, P);
	v.resize(N + 1);
	for (int i = 0; i < K; i++) {
		int X;
		cin >> X;
		Zombie[X] = true;
	}
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		v[X].push_back(Y);
		v[Y].push_back(X);
	}
	for (int i = 1; i <= N; i++) {
		if (Zombie[i]) {
			bfs(i);
		}
	}
	vector <ll> dist(N + 1, INF);
	priority_queue<pair<ll, int> > pq;
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (Zombie[next]) {
				continue;
			}
			ll ncost = cost + Cost[next];
			if (ncost < dist[next]) {
				dist[next] = ncost;
				pq.push(make_pair(-ncost, next));
			}
		}
	};

	cout << dist[N] - Cost[N] << endl;

	return 0;
}