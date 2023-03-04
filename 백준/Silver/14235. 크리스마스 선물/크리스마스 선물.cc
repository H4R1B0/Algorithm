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

int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	priority_queue<int> pq;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			for (int j = 0;j < a;j++) {
				int b;
				cin >> b;
				pq.push(b);
			}
		}
	}
}