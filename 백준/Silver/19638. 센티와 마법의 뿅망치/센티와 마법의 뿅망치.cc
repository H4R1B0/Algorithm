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

int N, H, T;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> pq;
	cin >> N >> H >> T;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int cnt = 0;
	while (T--) {
		int tmp = pq.top();
		if (tmp >= H) {
			if (tmp != 1) {
				tmp /= 2;
				pq.pop();
				pq.push(tmp);
				cnt++;
			}
		}
		else {
			cout << "YES" << endl;
			cout << cnt;
			return 0;
		}
	}

	if (pq.top() < H) {
		cout << "YES" << endl;
		cout << cnt;
	}
	else {
		cout << "NO" << endl;
		cout << pq.top();
	}
}