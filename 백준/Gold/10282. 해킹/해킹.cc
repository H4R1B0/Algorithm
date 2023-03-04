#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, D, C;
int Time[MAX];
vector<pair<int, int>> V[MAX];

void Initialize() {
	for (int i = 0;i < MAX;i++) {
		Time[i] = INF;
		V[i].clear();
	}		
}
void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,C });
	Time[C] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < V[cur].size();i++) {
			int next = V[cur][i].first;
			int ncost = V[cur][i].second;

			if (Time[next] > cost + ncost) {
				Time[next] = cost + ncost;
				pq.push({ -Time[next], next });
			}
		}
	}
}

int main(void)
{
	int Tc;
	cin >> Tc;
	while (Tc--) {
		Initialize();

		cin >> N >> D >> C;
		for (int i = 0;i < D;i++) {
			int a, b, s;
			cin >> a >> b >> s;
			//V[a].push_back({ b,s });
			V[b].push_back({ a,s });
		}
		dijkstra();
		vector<int> result;
		for (int i = 1;i <= N;i++) {
			if (Time[i] != INF) {
				result.push_back(Time[i]);
			}
		}
		sort(result.begin(), result.end());
		cout << result.size() << " " << result[result.size() - 1] << endl;
	}
}