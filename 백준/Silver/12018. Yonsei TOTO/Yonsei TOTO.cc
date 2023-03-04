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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0;i < N;i++) {
		int P, L;
		cin >> P >> L;
		vector<int> v(P);
		for (int j = 0;j < P;j++) {
			cin >> v[j];
		}
		if (P < L) {
			pq.push(1);
		}
		else {
			sort(v.begin(), v.end());
			pq.push(v[P-L]);
		}
	}

	int sum = 0, cnt = 0;
	while (!pq.empty() && sum + pq.top() <= M) {
		sum += pq.top();
		cnt++;
		pq.pop();
	}
	cout << cnt;
}