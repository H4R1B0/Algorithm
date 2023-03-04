#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, T, L;
vector<pair<int, pair<int, int>>> v[MAX];
vector<vector<int>> dist(MAX, vector<int>(10001, INF));

struct INFO {
	int time, cost, cur;
};
struct cmp {
	bool operator()(INFO a, INFO b) {
		return a.time > b.time;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> T >> M;
	cin >> L;
	for (int i = 0;i < L;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a].push_back({ b,{c,d} });
		v[b].push_back({ a,{c,d} });
	}

	//시간,돈,위치
	priority_queue<INFO, vector<INFO>, cmp> pq;
	dist[1][0] = 0;
	pq.push({ 0,0,1 });
	while (!pq.empty()) {
		int time = pq.top().time;
		int cost = pq.top().cost;		
		int cur = pq.top().cur;
		pq.pop();

		if (dist[cur][cost] < time)
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int ncost = cost + v[cur][i].second.second;
			if (ncost > M)
				continue;
			int ntime = time + v[cur][i].second.first;
			int next = v[cur][i].first;
			if (dist[next][ncost] > ntime) {
				dist[next][ncost] = ntime;
				pq.push({ ntime,ncost,next });
			}
		}
	}
	
	for (int i = 0;i <= M;i++) {
		if (dist[N][i] <= T) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}