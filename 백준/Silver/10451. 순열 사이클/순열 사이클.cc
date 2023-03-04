#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


int T, N;
vector<int> v[MAX];
bool visit[MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}

	
}

int main() {
	cin >> T;
	while (T--) {
		memset(visit, false, sizeof(visit));
		for (int i = 1;i <= MAX;i++) {
			v[i].clear();
		}
		cin >> N;
		for (int i = 1;i <= N;i++) {
			int to;
			cin >> to;
			v[i].push_back(to);
		}
		int cnt = 0;
		for (int i = 1;i <= N;i++) {
			if (!visit[i]) {
				bfs(i);
				cnt++;
			}
		}

		cout << cnt << endl;
	}
}