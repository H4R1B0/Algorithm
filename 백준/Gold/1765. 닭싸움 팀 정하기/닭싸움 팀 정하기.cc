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

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int parent[MAX];
vector<int> Friend[MAX];
vector<int> Enemy[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	cin >> M;
	for(int i=0;i<M;i++){
		char c;
		int a, b;
		cin >> c >> a >> b;

		if (c == 'F') {
			Friend[a].push_back(b);
			Friend[b].push_back(a);
		}
		else {
			Enemy[a].push_back(b);
			Enemy[b].push_back(a);
		}
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j < Friend[i].size();j++) {
			int x = i;
			int y = Friend[i][j];

			if (Find(x) != Find(y)) {
				Union(x, y);
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		if (Enemy[i].size() == 0)
			continue;

		for (int j = 0;j < Enemy[i].size();j++) {
			int x = Enemy[i][j];

			for (int k = 0;k < Enemy[x].size();k++) {
				int y = Enemy[x][k];
				if (Find(x) != Find(y)) {
					Union(i, y);
				}
			}
			
		}
	}

	set<int> ans;
	for (int i = 1;i <= N;i++)
		ans.insert(parent[i]);
	cout << ans.size();
}