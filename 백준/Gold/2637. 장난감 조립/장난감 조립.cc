#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
long long middle[MAX];
long long out[MAX];
long long cnt[MAX][MAX];
vector<vector<pair<long long, long long>>> v;

int main() {
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0;i < M;i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		middle[a]++;
		v[b].push_back({ a,c });
	}

	queue<int> q;
	for (int i = 1;i <= N;i++) {
		if (middle[i] == 0) {
			q.push(i);
			cnt[i][i] = 1;
		}
	}
	while (!q.empty()) {
		long long cur = q.front();
		q.pop();

		for (auto p : v[cur]) {
			for (int i = 1;i <= N;i++) {
				cnt[p.first][i] += cnt[cur][i] * p.second;
			}
			middle[p.first]--;

			if (middle[p.first] == 0) {
				q.push(p.first);
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		if(cnt[N][i])
			cout << i << " " << cnt[N][i] << endl;
	}
}