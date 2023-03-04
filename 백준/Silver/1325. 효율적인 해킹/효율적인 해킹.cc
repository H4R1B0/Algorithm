#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<int> map[MAX];
vector<pair<int, int>> v;
bool visit[MAX];
int hacked = 1;

void dfs(int start) {
	visit[start] = true;

	for (int i = 0;i < map[start].size();i++) {
		int next = map[start][i];

		if (!visit[next]) {
			dfs(next);
			hacked++;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		map[b].push_back(a);
	}

	for (int i = 1;i <= N;i++) {
		memset(visit, false, sizeof(visit));
		dfs(i);
		v.push_back({ i,hacked });
		hacked = 1;
	}

	int result = 0;
	for (int i = 0;i < v.size();i++)
		result = max(result, v[i].second);

	for (int i = 0;i < v.size();i++) {
		if (v[i].second == result)
			cout << v[i].first << " ";
	}
}