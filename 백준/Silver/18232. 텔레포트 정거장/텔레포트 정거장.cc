#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 300000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int xd[] = { -2,-1,1,2,2,1,-1,-2 };
int yd[] = { 1,2,2,1,-1,-2,-2,-1 };

int N, M;
int S, E;
vector<int> v[MAX];
bool visit[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> S >> E;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<pair<int, int>> q;
	q.push({ S,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == E) {
			cout << cnt;
			return 0;
		}

		int next = cur + 1;
		if (next<MAX && !visit[next]) {
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}
		next = cur - 1;
		if (next >= 1 && !visit[next]) {
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}

		for (int i = 0;i < v[cur].size();i++) {
			next = v[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
}