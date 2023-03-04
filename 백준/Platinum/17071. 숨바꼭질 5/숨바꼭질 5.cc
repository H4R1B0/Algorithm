#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 500000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K;
int visit[MAX][2];

int sum(int n) {
	return n * (n + 1) / 2;
}

int bfs() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	memset(visit, -1, sizeof(visit));	

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur >= MAX || cur < 0) {
			continue;
		}
		if (visit[cur][cnt % 2] != -1) {
			continue;
		}
		visit[cur][cnt % 2] = cnt;
		q.push({ cur - 1,cnt + 1 });
		q.push({ cur + 1,cnt + 1 });
		q.push({ cur * 2,cnt + 1 });
	}

	for (int i = 0; i < MAX; i++) {
		int nk = K + sum(i);
		if (nk >= MAX) {
			break;
		}

		if (visit[nk][i % 2] != -1 && visit[nk][i % 2] <= i) {
			return i;
		}
	}

	return -1;
}

int main() {
	cin >> N >> K;
	cout << bfs();
}