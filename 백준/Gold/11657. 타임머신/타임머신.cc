#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 501
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
long long Dist[MAX];
vector<pair<pair<int,int>, int>> Edge;

void Solve() {
	Dist[1] = 0;
	for (int i = 1;i <= N - 1;i++) {
		for (int j = 0;j < Edge.size();j++) {
			int from = Edge[j].first.first;
			int to = Edge[j].first.second;
			int cost = Edge[j].second;

			if (Dist[from] == INF)
				continue;
			
			Dist[to] = min(Dist[to], Dist[from] + cost);
		}
	}

	for (int i = 0;i < Edge.size();i++) {
		int from = Edge[i].first.first;
		int to = Edge[i].first.second;
		int cost = Edge[i].second;

		if (Dist[from] == INF)
			continue;

		if (Dist[to] > Dist[from] + cost) {
			cout << -1 << endl;
			return;
		}

		
	}
	for (int i = 2;i <= N;i++) {
		if (Dist[i] == INF)
			cout << -1 << endl;
		else
			cout << Dist[i] << endl;
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 1;i <= N;i++)
		Dist[i] = INF;

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge.push_back({ {a,b},c });
	}
	Solve();
}