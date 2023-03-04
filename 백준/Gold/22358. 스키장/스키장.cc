#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K, S, T;
vector<pair<ll,ll>> v[MAX];
ll DP[MAX][11];

ll dfs(ll cur, ll k) {
	if (k > K)
		return -INF;
	if (cur == T && k==K)
		return 0;
	ll& ret = DP[cur][k];
	if (ret != -1)
		return ret;
	ret = -INF;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i].first;
		int ncost = v[cur][i].second;
		if (k < K && next < cur) {
			ret = max(ret, dfs(next, k + 1));
		}
		else if (next > cur) {
			ret = max(ret, dfs(next, k) + ncost);
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> S >> T;
	for (int i = 0;i < M;i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	memset(DP, -1, sizeof(DP));
	ll answer = dfs(S, 0);
	cout << (answer < 0 ? -1 : answer);
}