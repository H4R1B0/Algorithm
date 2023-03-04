#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1;t <= T;t++) {
		cin >> N >> M;
		vector<vector<pair<int, int>>> v(M);
		for (int i = 0;i < N;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		vector<int> prev(M, -1);
		vector<int> dist(M, INF);
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,0 });
		while (!pq.empty()) {			
			int cost = -pq.top().first;
			int cur = pq.top().second;			
			pq.pop();

			if (cur == M - 1) {
				break;
			}
			
			if (dist[cur] < cost)
				continue;
			for (int i = 0;i < v[cur].size();i++) {
				int next = v[cur][i].first;
				int ncost = v[cur][i].second + cost;
				if (dist[next] > ncost) {
					dist[next] = ncost;
					pq.push({ -ncost,next });
					prev[next] = cur;
				}
			}
		}

		if (dist[M - 1] == INF) {
			cout << "Case #" << t << ": -1"<< endl;
			continue;
		}
		else {
			stack<int> answer;
			for (int i = M - 1;i > 0;)
				answer.push(i=prev[i]);
			cout << "Case #" << t << ": ";
			while (!answer.empty()) {
				cout << answer.top() << " ";
				answer.pop();
			}
			cout << M - 1 << endl;
		}
	}
}