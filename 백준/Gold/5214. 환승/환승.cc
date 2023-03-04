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

int N, K, M;
int dist[MAX+1000];
vector<int> v[MAX+1000];

int bfs() {
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == N)
			return dist[cur];

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!dist[next]) {
				if (next > N)
					dist[next] = dist[cur];
				else
					dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> K >> M;
	for (int i = 1;i <= M;i++) {
		for (int j = 0;j < K;j++) {
			int a;
			cin >> a;
			v[a].push_back(i + N);
			v[i + N].push_back(a);
		}
	}

	cout << bfs();
}