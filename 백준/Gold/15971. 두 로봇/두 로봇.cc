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
#define MAX 100000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, R1, R2;
int dist[MAX];
int max_dist[MAX];
bool visit[MAX];
vector<pair<int, int>> v[MAX];

void dfs(int start,int distance, int Max) {
	dist[start] = distance;
	max_dist[start] = Max;
	visit[start] = true;

	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i].first;
		int ncost = v[start][i].second;

		if (!visit[next]) {
			dfs(next, distance + ncost, max(Max, ncost));
		}
	}
}

int main() {
	cin >> N >> R1 >> R2;
	for (int i = 0;i < N-1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	if (R1 == R2) {
		cout << 0 << endl;
		return 0;
	}

	dfs(R1, 0, 0);
	cout << dist[R2] - max_dist[R2];
}