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

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	priority_queue<int> pq;
	int L, P;
	cin >> L >> P;

	int i = 0, cnt = 0;
	bool flag = false;
	while (P < L) {
		while (i < N && P >= v[i].first) {
			pq.push(v[i].second);
			i++;
		}
		if (pq.empty()) {
			cout << -1;
			return 0;
		}

		P += pq.top();
		pq.pop();
		cnt++;
	}
	cout << cnt;
}