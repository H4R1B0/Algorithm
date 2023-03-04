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
#define MAX 50+1
#define INF -987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, Start, End, M;
long long dist[MAX];
int city[MAX];
vector<tuple<int,int,int>> e;
bool visit[MAX];

bool dfs(int cur) {
	if (cur == End)
		return true;
	visit[cur] = true;
	bool chk = false;
	for (auto x : e) {
		int from = get<0>(x);
		int to = get<1>(x);
		int cost = get<2>(x);

		if (from == cur && !visit[to])
			chk |= dfs(to);
	}
	return chk;
}

int main() {
	cin >> N >> Start >> End >> M;

	for (int i = 0;i < N;i++)
		dist[i] = INF;

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ a,b,c });
	}

	for (int i = 0;i < N;i++)
		cin >> city[i];

	dist[Start] = city[Start];

	for (int i = 0;i < N - 1;i++) {
		for (auto x : e) {
			int from = get<0>(x);
			int to = get<1>(x);
			int cost = get<2>(x);

			if (dist[from] != INF && (dist[to] < dist[from] - cost + city[to]))
				dist[to] = dist[from] - cost + city[to];
		}
	}

	if (dist[End] == INF)
		cout << "gg";
	else {
		for (auto x : e) {
			int from = get<0>(x);
			int to = get<1>(x);
			int cost = get<2>(x);

			if (dist[from] != INF && (dist[to] < dist[from] - cost + city[to]))
				if (dfs(from)) {
					cout << "Gee";
					return 0;
				}
		}
		cout << dist[End];
	}
	return 0;
}