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
struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top().second << endl;
				pq.pop();
			}
		}
		else {
			pq.push({abs(a),a});
		}
	}
}