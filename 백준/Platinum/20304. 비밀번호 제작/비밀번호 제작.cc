#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<bool> visit;
vector<int> depth;
int cal(int num) {
	int cnt = 0;

	while (1) {
		if (num / 2 != 0) {
			cnt++;
			num /= 2;
		}

		else {
			cnt++;
			break;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	visit.resize(N + 1,false);
	depth.resize(N + 1,0);
	int max_cnt = cal(N);

	vector<int> p;
	cin >> M;
	for (int i = 0;i < M;i++) {
		int a;
		cin >> a;
		p.push_back(a);
	}

	queue<int> q;
	for (int i = 0;i < p.size();i++) {
		q.push(p[i]);
		visit[p[i]] = true;
		depth[p[i]] = 0;
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < max_cnt;i++) {
			int next = (cur ^ (1 << i));
			if (next <= N && !visit[next]) {
				visit[next] = true;
				depth[next] = depth[cur] + 1;
				q.push(next);
			}
		}
	}

	int answer = -1;
	for (int i = 0;i <= N;i++) {
		answer = max(answer, depth[i]);
	}
	cout << answer;
}