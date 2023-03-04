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
	priority_queue<int,vector<int>, greater<int>> pq;
	for (int i = 0;i < N * N;i++) {
		int a;
		cin >> a;
		if (pq.size() < N)
			pq.push(a);
		else if (a > pq.top()) {
			pq.pop();
			pq.push(a);
		}
	}
	cout << pq.top();
}