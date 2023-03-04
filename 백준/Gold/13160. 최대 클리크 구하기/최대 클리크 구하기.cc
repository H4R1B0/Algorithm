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

	vector<pair<int, int>> arr;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,-1 });
		arr.push_back({ b,1 });
		v.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	int cnt = 0, Max = 0, pos = 0;
	for (auto i : arr) {
		cnt += i.second;
		if (cnt < Max) {
			Max = cnt;
			pos = i.first;
		}
	}
	cout << -Max << endl;
	for (int i = 0;i < N;i++) {
		if (v[i].first <= pos && pos <= v[i].second) {
			cout << i + 1 << " ";
		}
	}
}