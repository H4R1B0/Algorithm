#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;

bool visit[MAX];
vector<int> v[MAX];

void dfs(int start, int cnt) {
	visit[start] = true;
	if (cnt == 4) {
		cout << 1;
		exit(0);
	}

	for (int i = 0;i < v[start].size();i++) {
		if (!visit[v[start][i]])
			dfs(v[start][i], cnt + 1);
	}
	visit[start] = false;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0;i < M;i++) {
		//memset(visit, false, sizeof(visit));
		dfs(i, 0);
	}
	cout << 0;
}