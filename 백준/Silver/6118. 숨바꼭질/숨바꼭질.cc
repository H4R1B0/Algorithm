#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 20000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<int> map[MAX];
int dist[MAX], result;
vector<int> result_v;

void bfs() {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
			
		for (int i = 0;i < map[cur].size();i++) {
			int next = map[cur][i];
			int ncost = cost + 1;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });

				if (dist[next] > result) {
					result = dist[next];
					result_v.clear();
					result_v.push_back(next);
				}
				else {
					result_v.push_back(next);
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		dist[i] = INF;
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	bfs();
	sort(result_v.begin(), result_v.end());
	cout << result_v[0] << " " << result << " " << result_v.size();
}