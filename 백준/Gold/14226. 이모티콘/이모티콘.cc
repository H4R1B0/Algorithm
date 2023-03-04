#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int S;
bool visit[MAX][MAX];


void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,0},0 });
	visit[1][0] = true;;

	while (!q.empty()) {
		int dis = q.front().first.first;
		int clip = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (dis == S) {
			cout << cnt;
			return;
		}

		if (dis > 0 && dis < MAX) {
			if (!visit[dis][dis]) {
				visit[dis][dis] = true;
				q.push({ {dis,dis},cnt + 1 });
			}
			if (!visit[dis - 1][clip]) {
				visit[dis - 1][clip] = true;
				q.push({ {dis-1,clip},cnt + 1 });
			}
		}
		if (clip > 0 && dis + clip < MAX) {
			if (!visit[dis + clip][clip]) {
				visit[dis + clip][clip] = true;
				q.push({ {dis + clip,clip},cnt + 1 });
			}
		}
	}
}

int main(void)
{
	cin >> S;
	bfs();
}