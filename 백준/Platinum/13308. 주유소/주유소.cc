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
#include <map>

using namespace std;

#define endl '\n'
#define MAX 2500+1
//#define INF 987654321
#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int prices[MAX];
long long costs[MAX][MAX];
vector<pair<int, int>> v[MAX];

long long dijkstra() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j < MAX;j++) {
			costs[i][j] = INF;
		}
	}

	priority_queue<pair<long long, pair<int, int>>> pq;
	pq.push({ 0,{1,prices[1]} });

	while (!pq.empty()) {
		long long total = -pq.top().first;
		int cur = pq.top().second.first;
		int price = pq.top().second.second;
		pq.pop();

		if (costs[cur][price] < total)
			continue;
		if (cur == N)
			return total;

		for (int i = 0;i < v[cur].size();i++) {
			long long ntotal = total + v[cur][i].second * price;
			int next = v[cur][i].first;
			int nprice = min(price, prices[next]);

			if (costs[next][price] > ntotal) {
				costs[next][price] = ntotal;
				pq.push({ -ntotal,{next,nprice} });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		cin >> prices[i];
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cout << dijkstra();
}