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

int N, M, num;
stack<int> st;
vector<int> v[MAX];
bool visit[MAX];

void scc(int node) {
	if (!visit[node]) {
		visit[node] = true;
		for (auto nx : v[node])
			scc(nx);
		st.push(node);
		num++;
	}
}

void bfs(int start) {
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto nx : v[curr]) {
			if (!visit[nx]) {
				visit[nx] = 1;
				q.push(nx);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		num = 0;
		int cnt = 0;
		for (int i = 1;i <= N;i++)
			v[i].clear();
		memset(visit, false, sizeof(visit));
		for (int i = 0;i < M;i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		for (int i = 1;i <= N;i++)
			scc(i);
		memset(visit, false, sizeof(visit));

		while (!st.empty()) {
			int curr = st.top();
			st.pop();
			if (!visit[curr]) {
				cnt++;
				bfs(curr);
			}
		}

		cout << cnt << endl;
	}
}