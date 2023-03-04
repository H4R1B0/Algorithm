#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, S, D, F, B, K;
bool visit[MAX];
set<int> polices;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S >> D >> F >> B >> K;
	for (int i = 0;i < K;i++) {
		int a;
		cin >> a;
		polices.insert(a);
	}

	queue<pair<int, int>> q;
	q.push({ S,0 });
	visit[S] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == D) {
			cout << cnt;
			return 0;
		}

		int next = cur + F;
		if (next <= N && !visit[next] && polices.count(next)==0) {
			visit[next] = true;
			q.push({ next, cnt + 1 });
		}

		next = cur - B;
		if (next >= 1 && !visit[next] && polices.count(next) == 0) {
			visit[next] = true;
			q.push({ next, cnt + 1 });
		}
	}

	cout << "BUG FOUND";
}