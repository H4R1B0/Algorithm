#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
vector<int> v[MAX];
bool visit[MAX];

bool dfs(int cur, int justbefore) {
	visit[cur] = true;

	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];

		if (next == justbefore)
			continue;
		if (visit[next])
			return false;
		if (dfs(next, cur) == false)
			return false;
	}
	return true;
}

int main() {
	int idx = 1;
	while (1) {		
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		int ans = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= N; ++i)
			v[i].clear();

		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= N; ++i)
			if (!visit[i])
				if (dfs(i, 0))
					ans++;

		cout << "Case " << idx++;
		if (ans == 0)
			cout << ": No trees.";
		else if (ans == 1)
			cout << ": There is one tree.";
		else
			cout << ": A forest of " << ans << " trees.";
		cout << endl;
	}
}