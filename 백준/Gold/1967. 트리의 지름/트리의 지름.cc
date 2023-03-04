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


int N;
int result, endP;
bool visit[MAX];
vector<pair<int, int>> v[MAX];

void dfs(int start, int len) {
	if (visit[start])
		return;
	visit[start] = true;
	if (result < len) {
		result = len;
		endP = start;
	}

	for (int i = 0;i < v[start].size();i++) {
		dfs(v[start][i].first, len + v[start][i].second);
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dfs(1, 0);
	//cout << endP << endl;
	//cout << result << endl;
		
	result = 0;
	memset(visit, false, sizeof(visit));
	dfs(endP, 0);
	cout << result;
}