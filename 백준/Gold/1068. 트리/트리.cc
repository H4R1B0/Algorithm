#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 51
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int result, del_node;
bool deleted[MAX];
vector<int> v[MAX];


void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		deleted[cur] = true;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!deleted[next])
				q.push(next);
		}
	}
}

int main() {
	cin >> N;

	int start = 0;
	for (int i = 0;i < N;i++) {
		int x;
		cin >> x;
		if (x == -1) {
			start = i;
			continue;
		}
		v[x].push_back(i);
	}
	int delete_num;
	cin >> delete_num;
	bfs(delete_num);

	for (int i = 0;i < N;i++) {
		if (!deleted[i]) {
			int j = 0;
			for (j = 0;j < v[i].size();j++) {
				if (!deleted[v[i][j]])
					break;
			}
			if (j == v[i].size())
				result++;
		}
	}
	cout << result;
}