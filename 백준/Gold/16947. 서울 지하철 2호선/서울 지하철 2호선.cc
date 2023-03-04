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
#define MAX 3000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N;
bool Cycle;
vector<int> v[MAX];
bool visit[MAX];
bool check_Cycle[MAX];

void dfs(int Cur, int Start, int Line) {
	if (Cur == Start && Line >= 2) {
		Cycle = true;
		return;
	}

	visit[Cur] = true;
	for (int i = 0;i < v[Cur].size();i++) {
		int next = v[Cur][i];

		if (!visit[next]) {
			dfs(next, Start, Line + 1);
		}
		else {
			if (next == Start && Line >= 2)
				dfs(next, Start, Line);
		}

		if (Cycle == true)
			return;
	}
}

int bfs(int start) {
	memset(visit, false, sizeof(visit));
	queue<pair<int,int>> q;
	q.push({start,0});
	visit[start] = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (check_Cycle[cur])
			return cnt;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];

			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1;i <= N;i++) {
		memset(visit, false, sizeof(visit));
		Cycle = false;
		dfs(i, i, 0);
		if (Cycle == true) {
			check_Cycle[i] = true;
		}
	}

	vector<int> result;
	for (int i = 1;i <= N;i++) {
		if (check_Cycle[i]) {
			result.push_back(0);
			continue;
		}
		result.push_back(bfs(i));
	}

	for (int i = 0;i < result.size();i++)
		cout << result[i] << " ";
}