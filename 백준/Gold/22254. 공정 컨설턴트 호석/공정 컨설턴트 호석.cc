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
#define MAX 100000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, X;
vector<int> Presents;
struct INFO
{
	ll sum;
	int line_num;
};
struct cmp
{
	bool operator()(INFO a, INFO b) {
		return a.sum > b.sum;
	}
};

bool check(int mid) {
	//cout << 1;
	ll Max=0;
	vector<pair<ll, int>> v(mid);
	priority_queue<INFO, vector<INFO>, cmp> pq;
	for (int i = 0;i < mid;i++) {
		pq.push({ 0,i });
	}
	for (int i = 0;i < Presents.size();i++) {
		ll sum = pq.top().sum+ Presents[i];
		int line_num = pq.top().line_num;
		pq.pop();
		Max = max(Max, sum);
		pq.push({ sum,line_num });
	}
	//cout << 1;
	if (Max > X)
		return false;
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> X;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		Presents.push_back(a);
	}

	int answer = INF;
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right)/2;
		if (check(mid)) {
			//cout << 1;
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
			left = mid + 1;
	}
	cout << answer;
}