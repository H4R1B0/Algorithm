#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 300000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<pair<int, int>> v;
	vector<int> bag;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0;i < K;i++) {
		int a;
		cin >> a;
		bag.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(bag.begin(), bag.end());

	ll ans = 0;
	int idx = 0;
	priority_queue<int> pq;
	for (int i = 0;i < K;i++) {
		while (idx < N && v[idx].first <= bag[i])
			pq.push(v[idx++].second);

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}