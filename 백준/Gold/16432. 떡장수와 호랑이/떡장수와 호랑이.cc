#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
set<int> s[MAX];
int result[MAX];
bool visit[MAX][10];

void dfs(int idx, int before) {
	if (idx == N+1) {
		for (int i = 1;i <= N;i++) {
			cout << result[i] << endl;
		}
		exit(0);
	}

	for (int i = 1;i < 10;i++) {
		if (i != before && !visit[idx + 1][i] && s[idx].count(i) != 0) {
			visit[idx + 1][i] = true;
			result[idx] = i;
			dfs(idx + 1, i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> M;
		for (int j = 0;j < M;j++) {
			int a;
			cin >> a;
			s[i].insert(a);
		}
	}
	dfs(1,0);
	cout << -1;
}