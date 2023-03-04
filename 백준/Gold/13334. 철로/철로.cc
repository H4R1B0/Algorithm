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

int N, M, D;

bool cmp1(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
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

	cin >> N;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		v.push_back({ a,b });
	}
	cin >> D;
	sort(v.begin(), v.end(), cmp1);
	int cnt = 0;
	for (int i = 0;i < v.size();i++) {
		int Start = v[i].first;
		int End = v[i].second;

		if (End - Start <= D)
			pq.push(Start);
		else
			continue;

		while (!pq.empty()) {
			int tmp = pq.top();
			if (End - tmp <= D)
				break;
			else
				pq.pop();
		}
		cnt = max(cnt, (int)pq.size());
	}
	cout << cnt;
}