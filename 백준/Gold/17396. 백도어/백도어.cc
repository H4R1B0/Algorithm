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
#define MAX 100000+1
//#define INF 987654321
#define INF 10000000000
#define ull long long

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;

int main() {
	cin >> N >> M;
	vector<bool> forbidden(N, false);
	vector<vector<pair<int, int>>> graph;
	for (int i = 0, t; i < N; i++) {
		cin >> t;
		forbidden[i] = (t == 1 ? true : false);
		vector<pair<int, int>> v;
		graph.push_back(v);
	}
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		if (forbidden[a] || forbidden[b]) {
			if (a != N - 1 && b != N - 1)
				continue;
		}
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	vector<ull> dist(N, INF);
	priority_queue<pair<ull, int>> pq;
	pq.push({ 0,0 });
	dist[0] = 0;

	while (pq.size())	{
		ull curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (dist[curNode] < curDist)
			continue;
		for (int i = 0; i < graph[curNode].size(); i++)		{
			ull nxtDist = curDist + graph[curNode][i].second;
			int nxtNode = graph[curNode][i].first;
			if (nxtDist < dist[nxtNode])			{
				dist[nxtNode] = nxtDist;
				pq.push({ -nxtDist, nxtNode });
			}
		}
	}
	if (dist[N - 1] == INF)
		cout << -1 << endl;
	else
		cout << dist[N - 1] << endl;
}