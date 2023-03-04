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

int N;
int dp[MAX];
int build_time[MAX], entry[MAX];
vector<int> v[MAX];

void bfs() {
	queue<int> q;
	for (int i = 1;i <= N;i++) {
		if (entry[i] == 0) {
			q.push(i);
			dp[i] = build_time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			entry[next]--;

			dp[next] = max(dp[next], dp[cur] + build_time[next]);
			if (entry[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1;i <= N;i++) {
		cout << dp[i] << endl;
	}
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> build_time[i];
		while (true) {
			int a;
			cin >> a;
			if (a == -1)
				break;
			v[a].push_back(i);
			entry[i]++;
		}
	}
	bfs();
}