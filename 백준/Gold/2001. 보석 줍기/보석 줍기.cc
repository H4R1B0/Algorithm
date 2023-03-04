#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
bool visit[MAX][1 << 16];
vector<pair<int, int>> v[MAX];
vector<int> jewel(MAX);

void bfs() {
	int ans = 0;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 1,{0,0} });
	visit[1][0] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int state = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (cur == 1) {
			int ncnt = cnt;
			if (jewel[1] && cnt < 14 && !(state&(1<<1)))
				ncnt++;
			ans = max(ans, ncnt);
		}

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int limit = v[cur][i].second;
			int jewel_num = jewel[next];

			if (jewel_num) {
				int nstate = state | (1 << jewel_num);
				if (cnt + 1 <= limit && !visit[next][nstate] && !(state&(1<<jewel_num))) {
					visit[next][nstate] = true;
					q.push({ next, {nstate,cnt + 1} });
				}
			}
			if (cnt > limit || visit[next][state])
				continue;
			visit[next][state] = true;
			q.push({ next, {state,cnt} });
		}
	}
	cout << ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1;i <= K;i++) {
		int a;
		cin >> a;
		jewel[a] = i;
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	bfs();
}