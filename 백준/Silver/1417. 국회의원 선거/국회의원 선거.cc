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

int N, M, D;

bool cmp1(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
struct cmp2
{
	bool operator()(pair<int, int> a, pair<int, int>b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Max;
	cin >> N;
	cin >> Max;
		
	priority_queue<int> pq;
	for (int i = 1;i < N;i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int cnt = 0;
	while (!pq.empty()) {
		if (Max + cnt > pq.top())
			break;
		int tmp = pq.top();
		pq.pop();
		tmp--;
		pq.push(tmp);
		cnt++;
	}
	cout << cnt;
}