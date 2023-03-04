#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, D;
int dist[MAX];
vector<pair<int, int>> v[MAX];


int main() {
	cin >> N >> D;
	for (int i = 0;i <= D;i++)
		dist[i] = i;
	for (int i = 0;i < N;i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (to - from <= cost)
			continue;
		if (to > D)
			continue;
		v[from].push_back({ to,cost });
	}
	
	int before;
	for (int i = 0;i <= D;i++) {
		if (i == 0)
			before = -1;
		else
			before = dist[i - 1];
		dist[i] = min(before + 1, dist[i]);
		if (!v[i].empty()) {
			for (int k = 0;k < v[i].size();k++) {
				int to = v[i][k].first;
				int cost = v[i][k].second;

				if (to > D)
					continue;
				if (dist[to] > dist[i] + cost)
					dist[to] = dist[i] + cost;
			}
		}
	}
	cout << dist[D];
}