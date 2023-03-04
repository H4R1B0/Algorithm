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

int C, N, M;

bool cmp(pair<int, bool> a, pair<int, bool> b) {
	return a.first < b.first;
}
struct pq_cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second)
			return a.second > b.second;
		return a.first > b.first;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C >> N;
	vector<pair<int,bool>> T_v;
	for (int i = 0;i < C;i++) {
		int a;
		cin >> a;
		T_v.push_back({a,false});
	}
	sort(T_v.begin(), T_v.end(),cmp);
	priority_queue<pair<int, int>, vector<pair<int, int>>, pq_cmp> pq;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}
	int cnt = 0;
	while (!pq.empty()) {
		for (int i = 0;i < C;i++) {
			if (T_v[i].first >= pq.top().first && T_v[i].first <= pq.top().second && !T_v[i].second) {
				cnt++;
				T_v[i].second = true;
				break;
			}
		}
		pq.pop();
	}
	cout << cnt;
}