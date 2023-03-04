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

	int T;
	cin >> T;
	while (T--) {
		priority_queue<pair<int, int>> Max_pq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min_pq;
		cin >> N;
		vector<bool> valid(N, false);
		for (int i = 0;i < N;i++) {
			char a;
			int b;
			cin >> a >> b;
			if (a == 'I') {
				Max_pq.push({ b,i });
				Min_pq.push({ b,i });
				valid[i] = true;
			}
			else {
				if (b == 1) {
					while (!Max_pq.empty() && !valid[Max_pq.top().second]) {
						Max_pq.pop();
					}
					if (!Max_pq.empty()) {
						valid[Max_pq.top().second] = false;
						Max_pq.pop();
					}
				}
				else {
					while (!Min_pq.empty() && !valid[Min_pq.top().second]) {
						Min_pq.pop();
					}
					if (!Min_pq.empty()) {
						valid[Min_pq.top().second] = false;
						Min_pq.pop();
					}
				}
			}
		}
		while (!Max_pq.empty() && !valid[Max_pq.top().second]) {
			Max_pq.pop();
		}
		while (!Min_pq.empty() && !valid[Min_pq.top().second]) {
			Min_pq.pop();
		}
		if (Max_pq.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << Max_pq.top().first << " " << Min_pq.top().first << endl;
		}
	}
}