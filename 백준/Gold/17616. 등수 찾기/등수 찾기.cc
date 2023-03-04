#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, X;
vector<int> v[MAX];
vector<int> reverse_v[MAX];
bool visit[MAX];
int cnt, reverse_cnt;

void dfs(int cur) {
	if (visit[cur])
		return;
	visit[cur] = true;
	cnt++;

	for (auto next : v[cur]) {
		dfs(next);
	}
}

void reverse_dfs(int cur) {
	if (visit[cur])
		return;
	visit[cur] = true;
	reverse_cnt++;

	for (auto next : reverse_v[cur]) {
		reverse_dfs(next);
	}
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		reverse_v[b].push_back(a);
	}
	dfs(X);
	memset(visit, false, sizeof(visit));
	reverse_dfs(X);

	cout << reverse_cnt << ' ' << N - cnt + 1 << endl;
}