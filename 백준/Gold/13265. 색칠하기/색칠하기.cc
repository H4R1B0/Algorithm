#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int N, M;
bool flag;
vector<int> circle;
vector<vector<int>> line;

void dfs(int idx) {
	for (auto i : line[idx]) {
		if (!circle[i]) {
			circle[i] = 3 - circle[idx];
			dfs(i);
		}
		if (circle[idx] == circle[i])
			flag = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		circle = vector<int>(N + 1);
		line = vector<vector<int>>(N + 1);
		for (int i = 0;i < M;i++) {
			int a, b;
			cin >> a >> b;
			line[a].push_back(b);
			line[b].push_back(a);
		}
		flag = true;
		for (int i = 1;i <= N;i++) {
			if (!circle[i]) {
				circle[i] = 1;
				dfs(i);
			}
		}
		if (flag)
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;
	}
}