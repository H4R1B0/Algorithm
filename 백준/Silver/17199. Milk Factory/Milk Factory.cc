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
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
vector<int> v[MAX];
bool visit[MAX];

void dfs(int cur) {
	visit[cur] = true;
	for (auto next : v[cur]) {
		if (!visit[next])
			dfs(next);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N-1;i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1;i <= N;i++) {
		memset(visit, false, sizeof(visit));
		dfs(i);
		bool flag = true;
		for (int i = 1;i <= N;i++) {
			if (!visit[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}