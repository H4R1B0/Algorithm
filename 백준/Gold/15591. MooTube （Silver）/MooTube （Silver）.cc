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
#define MAX 5000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, Q;
int K, V;
bool visit[MAX];
vector<pair<int, int>> v[MAX];

int bfs() {
	memset(visit, false, sizeof(visit));
	int result = 0;
	queue<int> q;
	q.push(V);
	visit[V] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int ncnt = v[cur][i].second;

			if (!visit[next]) {
				if (ncnt >= K) {
					visit[next] = true;
					result++;
					q.push(next);
				}
			}
		}
	}
	return result;
}

int main() {
	cin >> N >> Q;
	for (int i = 0;i < N - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 0;i < Q;i++) {
		cin >> K >> V;
		cout << bfs() << endl;
	}
}