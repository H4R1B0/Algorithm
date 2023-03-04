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

int N, M;
vector<int> map[MAX];
bool visit[MAX];

void dfs(int start) {
	for (int i = 0;i < map[start].size();i++) {
		int next = map[start][i];
		visit[next] = true;
	}

	if (start == 1) {
		for (int i = 0;i < map[start].size();i++) {
			int next = map[start][i];
			dfs(next);
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	dfs(1);

	int cnt = 0;
	for (int i = 2;i <= N;i++) {
		if (visit[i])
			cnt++;
	}
	cout << cnt;
}