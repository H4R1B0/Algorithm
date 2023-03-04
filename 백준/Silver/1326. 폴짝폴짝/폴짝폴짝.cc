#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0, 1, 1, 0, -1, -1 };
int yd[] = { 2, 1, -1, -2, -1, 1 };


int N, Start, End;
int jump[MAX];
int visit[MAX];

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> jump[i];
	cin >> Start >> End;
	queue<pair<int, int>> q;
	q.push({ Start,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == End) {
			cout << visit[End];
			return 0;
		}

		for (int i = 1;cur + jump[cur] * i <= N;i++) {
			int next = cur + jump[cur] * i;
			if (!visit[next]) {
				visit[next] = visit[cur] + 1;
				q.push({ next,cnt + 1 });
			}
		}
		for (int i = 1;cur - jump[cur] * i >= 1;i++) {
			int next = cur - jump[cur] * i;
			if (!visit[next]) {
				visit[next] = visit[cur] + 1;
				q.push({ next,cnt + 1 });
			}
		}
	}
	cout << -1;
}