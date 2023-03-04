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

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M;

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

		ll sum = 0;
		while (!pq.empty()) {
			if (pq.size() == 1) {
				cout << sum << endl;
				break;
			}
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			sum += (a + b);
			pq.push(a + b);
		}
	}
}