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
struct INFO
{
	int L, H, R;
};
bool cmp(INFO a, INFO b){
	if (a.L == b.L) {
		if (a.R == b.R)
			return a.H < b.H;
		return a.R < b.R;
	}
	return a.L < b.L;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<INFO> v;
	map<int, int> dic;
	for (int i = 0;i < N;i++) {
		int l, h, r;
		cin >> l >> h >> r;
		v.push_back({l,h,r});
		dic[l] = dic[r] = 0;
	}
	vector<int> arr;
	for (auto i : dic) {
		dic[i.first] = M++;
		arr.push_back(i.first);
	}
	sort(v.begin(), v.end(),cmp);
	int cur = 0;
	priority_queue<pair<int, int>> pq;
	for (int i = 0, j = 0;i < M;i++) {
		while (j < N && dic[v[j].L] <= i) {
			pq.push({ v[j].H,dic[v[j].R] });
			j++;
		}
		int next = 0;
		while (!pq.empty()) {
			if (i < pq.top().second) {
				next = pq.top().first;
				break;
			}
			pq.pop();
		}
		if (cur != next) {
			cur = next;
			cout << arr[i] << " " << cur<<" ";
		}
	}
}