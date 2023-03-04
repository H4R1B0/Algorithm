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
struct cmp
{
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	while (M--) {
		ll x = pq.top();
		pq.pop();
		ll y = pq.top();
		pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}
	ll sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout<<sum;
}