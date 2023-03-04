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
#define MAX 100000+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int A, B, N, M;
bool visit[MAX];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == M)
			return cnt;

		int next = cur + 1;
		if (next < MAX && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}

		next = cur - 1;
		if (next >= 0 && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}

		next = cur + A;
		if (next < MAX && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}
		next = cur - A;
		if (next >= 0 && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}

		next = cur + B;
		if (next < MAX && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}
		next = cur - B;
		if (next >= 0 && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}

		next = cur * A;
		if (next < MAX && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}

		next = cur * B;
		if (next < MAX && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}
	}
}

int main() {
	cin >> A >> B >> N >> M;
	cout << bfs();
}