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

bool cmp1(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}
struct cmp2
{
	bool operator()(pair<int, int> a, pair<int, int>b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp1);
	int day = 1;
	for (int i = 0;i < N;i++) {
		while (!pq.empty() && v[i].first < day) {
			if (pq.top().second > v[i].second)
				break;
			pq.pop();
			day--;
		}
		if (v[i].first >= day) {
			pq.push(v[i]);
			day++;
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top().second;
		pq.pop();
	}
	cout << ans;
}