#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500000+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, cnt;
int Entry[MAX];
vector<int> v[MAX];
bool visit[MAX];

void dfs(int start, int depth) {
	if (start != 1 && v[start].size()==1) {
		if (depth % 2 == 1)
			cnt++;
		return;
	}

	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i];
		if (!visit[start]) {
			visit[start] = true;
			dfs(next, depth + 1);
			visit[start] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1,0);
	if (cnt % 2 == 1)
		cout << "Yes";
	else
		cout << "No";
}