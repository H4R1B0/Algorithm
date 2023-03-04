#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int parent[MAX];
bool visit[MAX];
vector<int> path;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if (cur == M) {
			cout << cnt << endl;
			
			int idx = cur;
			while (idx != N) {
				path.push_back(idx);
				idx = parent[idx];
			}
			path.push_back(N);
			break;
		}

		int num = cur - 1;
		if (num>=0 && !visit[num]) {
			q.push({ num,cnt + 1 });
			visit[num] = true;
			parent[num] = cur;
		}

		num = cur + 1;
		if (num < MAX && !visit[num]) {
			q.push({ num,cnt + 1 });
			visit[num] = true;
			parent[num] = cur;
		}

		num = cur * 2;
		if (num < MAX && !visit[num]) {
			q.push({ num,cnt + 1 });
			visit[num] = true;
			parent[num] = cur;
		}
	}
}

int main() {
	cin >> N >> M;
	bfs();

	for (int i = path.size() - 1;i >= 0;i--)
		cout << path[i] << " ";
}