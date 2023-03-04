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

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N;

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
	
	priority_queue<int> pq;
	for (auto i : v) {
		pq.push(-i);
	}

	int ans = 0;
	int cnt = 0;
	while (!pq.empty()) {
		if (cnt == N - 1)
			break;

		int num1 = -pq.top();
		pq.pop();
		int num2 = -pq.top();
		pq.pop();

		ans += (num1 + num2);
		pq.push(-num1 - num2);
		cnt++;
	}
	cout << ans;
}