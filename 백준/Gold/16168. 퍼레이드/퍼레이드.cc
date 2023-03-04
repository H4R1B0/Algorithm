#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 3000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int V, E;
vector<int> v[MAX];
bool visit[MAX];

void dfs(int cur) {
	if (visit[cur])
		return;
	visit[cur] = true;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0;i < E;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	bool flag = false;
	for (int i = 1;i <= V;i++) {
		if (!visit[i]) {
			flag = true;
			break;
		}
	}
	int cnt = 0;
	for (int i = 1;i <= V;i++) {
		if (v[i].size() % 2 == 1) {
			cnt++;
		}
	}
	if (!flag && (cnt == 0 || cnt == 2))
		cout << "YES";
	else
		cout << "NO";
}