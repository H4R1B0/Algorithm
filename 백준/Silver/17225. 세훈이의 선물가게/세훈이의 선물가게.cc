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

int N, A, B;
struct INFO
{
	int who, et;
};
struct cmp
{
	bool operator()(INFO a, INFO b) {
		if (a.et == b.et)
			return a.who < b.who;
		return a.et > b.et;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> N;
	priority_queue<INFO, vector<INFO>, cmp>pq;
	for (int i = 0;i < N;i++) {
		int t, m;
		char c;
		cin >> t >> c >> m;
		if (c == 'B') {
			for (int i = 0;i < m;i++) {
				pq.push({ 0,t + (i + 1) * A });
			}
		}
		else {
			for (int i = 0;i < m;i++) {
				pq.push({ 1,t + (i + 1) * B });
			}
		}
	}
	vector<int> A_v, B_v;
	int num = 1;
	while (!pq.empty()) {
		INFO tmp = pq.top();
		pq.pop();
		if (tmp.who == 0) {
			A_v.push_back(num++);
		}
		else {
			B_v.push_back(num++);
		}
	}
	cout << A_v.size() << endl;
	for (auto i : A_v)
		cout << i << " ";
	cout << endl;
	cout << B_v.size() << endl;
	for (auto i : B_v)
		cout << i << " ";
}