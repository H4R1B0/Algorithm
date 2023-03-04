#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0;i < N;i++) {
			ll a;
			cin >> a;
			pq.push(a);
		}
		ll answer = 1;
		while (pq.size() != 1) {
			ll tmp1 = pq.top();
			pq.pop();
			ll tmp2 = pq.top();
			pq.pop();
			answer *= ((tmp1 % mod) * (tmp2 % mod)) % mod;
			pq.push(tmp1*tmp2);
			answer %= mod;
		}
		cout << answer << endl;
	}
}