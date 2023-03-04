#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10+1
#define INF 987654321
#define ll long long

int xd[8] = { 0,0,1,-1,1,1,-1,-1 };
int yd[8] = { 1,-1,0,0,1,-1,1,-1 };

int N;
ll dp[MAX];
vector<pair<int, pair<int, int>>> v[MAX];

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void dfs(int cur, int parent) {
	for (auto n : v[cur]) {
		if (n.first == parent)
			continue;

		dp[n.first] = dp[cur] * n.second.second / n.second.first;
		dfs(n.first, cur);
	}
}

int main() {
	cin >> N;
	ll lcm = 1;
	for (int i = 0;i < N - 1;i++) {
		ll a, b, p, q;
		cin >> a >> b >> p >> q;
		v[a].push_back({ b,{p,q} });
		v[b].push_back({ a,{q,p} });
		lcm *= (p * q / gcd(p, q));
	}
	dp[0] = lcm;
	dfs(0, -1);
	ll global = dp[0];
	for (int i = 1;i < N;i++) {
		if (dp[i] == 0)
			continue;
		global = gcd(global, dp[i]);
	}
		

	for (int i = 0;i < N;i++)
		cout << dp[i]/global << " ";
}