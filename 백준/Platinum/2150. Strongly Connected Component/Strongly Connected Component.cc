#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<int> v[MAX], e[MAX];
vector<int> result[MAX];
bool visit[MAX];
stack<int> st;

void dfs(int start) {
	visit[start] = true;
	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i];
		if (!visit[next])
			dfs(next);
	}
	st.push(start);
}

void redfs(int start, int cnt) {
	visit[start] = true;
	result[cnt].push_back(start);
	for (int i = 0;i < e[start].size();i++) {
		int next = e[start][i];
		if (!visit[next])
			redfs(next,cnt);
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		e[b].push_back(a);
	}

	for (int i = 1;i <= N;i++)
		if (!visit[i])
			dfs(i);

	memset(visit, false, sizeof(visit));

	int cnt = 0;

	while (!st.empty()) {
		int s = st.top();
		st.pop();
		if (visit[s])
			continue;
		redfs(s, cnt);
		cnt++;
	}
	cout << cnt << endl;
	vector <pair<int, int>> r;
	for (int i = 0; i < cnt; i++) {
		sort(result[i].begin(), result[i].end());
		r.push_back({ result[i][0],i });
	}
	sort(r.begin(), r.end());
	for (int i = 0;i < r.size();i++) {
		for (int j = 0;j < result[r[i].second].size();j++) {
			cout << result[r[i].second][j] << " ";
		}
		cout << -1 << endl;
	}
}