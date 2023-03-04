#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

struct INFO {
	int x, y, r;
};
int N;
bool circle[MAX][MAX];
vector<INFO> v;

int cal(int x1, int y1, int x2, int y2) {
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return x * x + y * y;
}

int bfs(int a) {
	vector<bool> visit(N, false);
	int cnt = 1;
	queue<int> q;
	q.push(a);
	visit[a] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < N;i++) {
			if (circle[cur][i] && !visit[i]) {
				visit[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({a,b,c});
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (i == j) {
				circle[i][j] = true;
				continue;
			}
			if (v[i].r * v[i].r >= cal(v[i].x, v[i].y, v[j].x, v[j].y)) {
				circle[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0;i < N;i++) {
		ans = max(ans, bfs(i));
	}
	cout << ans;
}