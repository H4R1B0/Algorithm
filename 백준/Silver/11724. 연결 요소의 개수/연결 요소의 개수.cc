#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1001
 
int N, M;
vector<int> ans[MAX];
bool visit[MAX];
queue<int> q;

void dfs(int start) {
	visit[start] = true;

	for (int i = 0;i < ans[start].size();i++) {
		int next = ans[start][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;

		ans[a].push_back(b);
		ans[b].push_back(a);
	}

	int cnt=0;

	for (int i = 1;i <= N;i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
}