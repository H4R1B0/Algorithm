#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


int F, S, G, U, D;
bool visit[MAX];


void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == G) {
			cout << cnt;
			return;
		}
		int up = cur + U;
		if (up >= 1 && up <= F && !visit[up]) {
			q.push({ up,cnt + 1 });
			visit[up] = true;
		}
		int down = cur - D;
		if (down >= 1 && down <= F && !visit[down]) {
			q.push({ down,cnt + 1 });
			visit[down] = true;
		}

		
	}

	cout << "use the stairs";
}

int main() {
	cin >> F >> S >> G >> U >> D;

	bfs(S);
}