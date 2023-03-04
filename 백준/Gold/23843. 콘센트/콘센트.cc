#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX (100+1)
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[] = { -1,0,1,0 };
int yd[] = { 0,1,0,-1 };

int N, M;
vector<ll> devices;
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	priority_queue<INFO, vector<INFO>, cmp> pq;
	for (int i = 0;i < N;i++) {
		ll a;
		cin >> a;
		devices.push_back(a);
	}
	sort(devices.begin(), devices.end());
	reverse(devices.begin(), devices.end());
	for (int i = 0;i < M;i++)
		pq.push({ 0,i });

	ll answer = 0;
	for (int i = 0;i < devices.size();i++) {
		ll sum = pq.top().sum + devices[i];
		int line_num = pq.top().line_num;
		//cout << sum <<" "<< line_num << endl;
		pq.pop();
		pq.push({ sum,line_num });
		answer = max(answer, sum);
	}
	cout << answer;
}