#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 10000+1
//#define INF 987654321987
#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
long long cost[MAX][21];
vector<pair<int,int>> v[MAX];

long long dijkstra(int start) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 21; j++)
			cost[i][j] = INF;
	}
	priority_queue<pair<long long, pair<int, int>>> pq;
	pq.push({ 0,{start,0} });
	cost[start][0] = 0;

	while (!pq.empty()) {
		long long cur_cost = -pq.top().first;
		int cur = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();

		if (cur_cost > cost[cur][cnt])
			continue;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			long long next_cost = cur_cost + v[cur][i].second;

			if (cnt < K) {
				if (cost[next][cnt + 1] > cur_cost) {
					cost[next][cnt + 1] = cur_cost;
					pq.push({ -cur_cost,{next,cnt + 1} });
				}
			}
			if (cost[next][cnt] > next_cost) {
				cost[next][cnt] = next_cost;
				pq.push({ -next_cost,{next,cnt} });
			}
		}
	}

	long long Min = cost[N][0];
	for (int i = 1;i <= K;i++) {
		if (Min > cost[N][i])
			Min = cost[N][i];
	}
	return Min;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cout << dijkstra(1);
}