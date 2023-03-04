#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, R, Q;
vector<int> map[MAX];
bool visit[MAX];
int num[MAX];

int dfs(int n) {
	if (num[n] != 0)
		return num[n];
	visit[n] = true;
	int ret = 1;
	for (int i = 0;i < map[n].size();i++) {
		int next = map[n][i];
		if (!visit[next])
			ret += dfs(next);
	}
	num[n] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> R >> Q;
	for (int i = 0;i < N - 1;i++) {
		int u, v;
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}

	num[R] = dfs(R);
	int u;
	for (int i = 0;i < Q;i++) {
		
		cin >> u;
		cout << num[u] << endl;
	}
}