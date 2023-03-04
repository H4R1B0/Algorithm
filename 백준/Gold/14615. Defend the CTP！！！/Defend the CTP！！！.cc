#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, T;
int target;
vector<int> v[2][MAX];
bool visit[2][MAX];

void dfs(int idx, int cur) {
	visit[idx][cur] = true;
	for (auto next : v[idx][cur]) {
		if (!visit[idx][next])
			dfs(idx, next);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[0][a].push_back(b);
		v[1][b].push_back(a);
	}

	dfs(0, 1);
	dfs(1, N);
	cin >> T;
	while (T--) {
		int a;
		cin >> a;
		if (visit[0][a] && visit[1][a])
			cout << "Defend the CTP" << endl;
		else
			cout << "Destroyed the CTP" << endl;
	}
}