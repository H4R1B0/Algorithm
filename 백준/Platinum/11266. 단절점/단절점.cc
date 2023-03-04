#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int V, E, cnt;
vector<int> map[MAX];
vector<int> result;
int visit[MAX];
bool cut[MAX];

int dfs(int here, bool root) {
	cnt++;
	visit[here] = cnt;
	int ret = visit[here];
	int child = 0;
	for (int i = 0;i < map[here].size();i++) {
		int next = map[here][i];
		if (visit[next]) {
			ret = min(ret, visit[next]);
			continue;
		}
		child++;
		int prev = dfs(next, false);
		if (!root && prev >= visit[here])
			cut[here] = true;
		ret = min(ret, prev);
	}
	if (root && child > 1)
		cut[here] = true;
	return ret;
}


int main(void)
{
	cin >> V >> E;
	for (int i = 0;i < E;i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1;i <= V;i++)
		if (!visit[i])
			dfs(i, true);
	for (int i = 1;i <= V;i++)
		if (cut[i])
			result.push_back(i);
	cout << result.size() << endl;
	for (int i = 0;i < result.size();i++)
		cout << result[i] << " ";
}