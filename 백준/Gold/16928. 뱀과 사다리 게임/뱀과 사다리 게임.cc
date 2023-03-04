#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX];
int cnt[MAX];

void bfs() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1;i <= 6;i++) {
			int next = cur + i;
			if (next > 100)
				continue;
			next = map[next];
			if (cnt[next] == -1) {
				cnt[next] = cnt[cur] + 1;
				q.push(next);
			}
		}
	}
	cout << cnt[100];
}

int main(void)
{
	for (int i = 1;i <= 100;i++) {
		map[i] = i;
		cnt[i] = -1;
	}

	cin >> N >> M;
	for (int i = 0;i < N + M;i++) {
		int a, b;
		cin >> a >> b;
		map[a] = b;
	}

	cnt[1] = 0;
	bfs();
}