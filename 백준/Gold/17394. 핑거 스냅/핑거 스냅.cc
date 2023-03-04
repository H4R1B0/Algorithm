#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 1000000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int N, A, B;
bool visit[MAX];

bool check(int x) {
	int m = sqrt(x);
	for (int i = 2;i <= m;i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int bfs() {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur >= A && cur <= B && check(cur)) {
			return cnt;
		}

		int next = cur / 2;
		if (next >= 0 && !visit[next]) {
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}
		next = cur / 3;
		if (next >= 0 && !visit[next]) {
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}
		next = cur + 1;
		if (next < MAX && !visit[next]) {
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}
		next = cur - 1;
		if (next >= 0 && !visit[next]) {
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		cout << bfs() << endl;
	}
}