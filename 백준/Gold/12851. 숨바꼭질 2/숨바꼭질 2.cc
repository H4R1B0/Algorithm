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

int N, K;
bool visit[MAX];
int cnt, result;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int sec = q.front().second;
		q.pop();

		visit[cur] = true;			

		if (result && result == sec && cur == K)
			cnt++;		

		if (!result && cur == K) {
			result = sec;
			cnt++;
		}

		if (cur + 1 < MAX && !visit[cur + 1])
			q.push({ cur + 1,sec + 1 });
		if (cur - 1 >= 0 && !visit[cur - 1])
			q.push({ cur - 1,sec + 1 });
		if (cur * 2 < MAX && !visit[cur * 2])
			q.push({ cur * 2,sec + 1 });
	}
}

int main(void)
{
	cin >> N >> K;
	bfs();
	cout << result << endl << cnt << endl;
}