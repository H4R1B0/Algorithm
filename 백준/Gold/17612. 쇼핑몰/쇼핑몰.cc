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

int N, K;
struct INFO
{
	int id, time, order;
};

bool cmp(INFO a, INFO b) {
	if (a.time == b.time)
		return a.order > b.order;
	return a.time < b.time;
}

struct pq_cmp
{
	bool operator()(INFO a, INFO b) {
		if (a.time == b.time)
			return a.order > b.order;
		return a.time > b.time;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<pair<int, int>> v;
	priority_queue<INFO, vector<INFO>, pq_cmp> pq;
	for (int i = 0;i < N;i++) {
		int id, w;
		cin >> id >> w;
		v.push_back({ id,w });
	}

	bool flag = false;
	vector<INFO> exit_order;
	for (int i = 0;i < K;i++) {
		if (i == N) {
			flag = true;
			break;
		}
		int id = v[i].first;
		int w = v[i].second;
		pq.push({ id,w,i + 1 });
	}

	if (flag) {
		while (!pq.empty()) {
			exit_order.push_back(pq.top());
			pq.pop();
		}
	}
	else {
		for (int i = K;i < N;i++) {
			int id = v[i].first;
			int w = v[i].second;
			pq.push({ id,w + pq.top().time,pq.top().order });
			exit_order.push_back(pq.top());
			pq.pop();
		}
		//cout << pq.size() << endl;
		while (!pq.empty()) {
			exit_order.push_back(pq.top());
			pq.pop();
		}
	}

	sort(exit_order.begin(), exit_order.end(),cmp);
	ll answer = 0;
	for (int i = 0;i < exit_order.size();i++) {
		answer += (i + 1) * (ll)exit_order[i].id;
	}
	cout << answer;
}