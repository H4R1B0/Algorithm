#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


int N, K;
bool visit[MAX];


void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == K) {
			cout << cnt;
			return;
		}
		int x3 = cur * 2;
		if (x3 >= 0 && x3 <= 100000 && !visit[x3]) {
			q.push({ x3,cnt });
			visit[x3] = true;
		}
		int x1 = cur - 1;
		if (x1 >= 0 && x1 <= 100000 && !visit[x1]) {
			q.push({ x1,cnt + 1 });
			visit[x1] = true;
		}
		int x2 = cur + 1;
		if (x2 >= 0 && x2 <= 100000 && !visit[x2]) {
			q.push({ x2,cnt + 1 });
			visit[x2] = true;
		}		
	}
}

int main() {
	cin >> N >> K;
	bfs(N);
}