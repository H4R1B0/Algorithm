#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> v;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	priority_queue<int> max_pq, min_pq;
	for (int i = 0;i < N;i++) {
		if (max_pq.size() == min_pq.size())
			max_pq.push(v[i]);
		else
			min_pq.push(-v[i]);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > -min_pq.top()) {
				int Max = max_pq.top();
				int Min = -min_pq.top();
				max_pq.pop(), min_pq.pop();
				max_pq.push(Min);
				min_pq.push(-Max);
			}
		}
		cout << max_pq.top() << endl;
	}
}