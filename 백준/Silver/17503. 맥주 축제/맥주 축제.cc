#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	cin >> N >> M >> K;
	for (int i = 0;i < K;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	int total = 0;
	for (int i = 0;i < v.size();i++) {
		pq.push(v[i].first);
		total += v[i].first;

		if (pq.size() > N) {
			total -= pq.top();
			pq.pop();
		}

		if (pq.size() == N && total >= M) {
			cout << v[i].second;
			return 0;
		}
	}
	cout << -1;
}