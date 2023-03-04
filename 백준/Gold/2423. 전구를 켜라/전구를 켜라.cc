#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
char g[MAX][MAX];
vector<pair<int, int>> v[510*510];
vector<int> dist(510*510, INF);
int cal(int a, int b) {
	return a * 502 + b;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//int idx = 1;
		
	//cout << "A";
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> g[i][j];
			if (g[i][j] == '/') {
				v[cal(i - 1, j - 1)].push_back({ cal(i,j),1 });
				v[cal(i, j)].push_back({ cal(i - 1,j - 1),1 });
				v[cal(i - 1, j)].push_back({ cal(i,j - 1),0 });
				v[cal(i, j - 1)].push_back({ cal(i - 1,j),0 });
			}
			else {
				v[cal(i - 1, j - 1)].push_back({ cal(i,j),0 });
				v[cal(i, j)].push_back({ cal(i - 1,j - 1),0 });
				v[cal(i - 1, j)].push_back({ cal(i,j - 1),1 });
				v[cal(i, j - 1)].push_back({ cal(i - 1,j),1 });
			}
		}
	}
	//cout << "a";
	priority_queue<pair<int, int>> pq;
	pq.push({0,0});
	dist[0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second + cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	if (dist[cal(N, M)] == INF)
		cout << "NO SOLUTION";
	else
		cout << dist[cal(N, M)];
}