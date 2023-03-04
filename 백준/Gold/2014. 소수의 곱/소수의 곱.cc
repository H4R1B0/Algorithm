#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int K, N, M;
set<int> s;
vector<ll> numbers;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	for (int i = 0;i < K;i++) {
		ll a;
		cin >> a;
		numbers.push_back(a);
	}
	pq.push(1);
	s.insert(1);
	ll Max = 0;
	while (N--) {
		ll cur = pq.top();
		pq.pop();

		for (auto i : numbers) {
			ll next = cur * i;
			if (s.count(next))
				continue;

			if (pq.size() > N) {
				if (Max <= next)
					continue;
			}

			pq.push(next);
			Max = max(Max, next);
			s.insert(next);
		}
	}
	cout << pq.top();
}