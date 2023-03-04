#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 10000000000
#define ll long long

//int xd[] = { 0,1 };
//int yd[] = { 1,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int dist[MAX];
bool flag = true;
pair<int, int> road;
vector<pair<int, int>> v[MAX];
vector<int> parent;

bool check(int a, int b) {
	if (a == road.first && b == road.second)
		return true;
	else if (b == road.first && a == road.second)
		return true;
	else
		return false;
}

int dijkstra() {
	vector<int> dist(N + 1, INF);
	dist[1] = 0;
	//cost,cur
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });	

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second + cost;

			if (check(cur,next))
				continue;			

			if (dist[next] > ncost) {
				if (flag)
					parent[next] = cur;
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	return dist[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	parent.resize(N + 1, -1);
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		//road.push_back({ a,b });
	}
	parent[1] = 1;	
	int origin = dijkstra();
	flag = false;
	
	int result = 0;
	for (int p = N;p != parent[p];p=parent[p]) {
		road = { p,parent[p] };
		
		result = max(result, dijkstra());
		
		if (result == INF)
			break;
	}
	
	if (result == INF)
		cout << -1;
	else
		cout << result - origin;
}