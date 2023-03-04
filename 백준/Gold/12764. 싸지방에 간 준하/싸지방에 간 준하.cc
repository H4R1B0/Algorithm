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
	vector<pair<int, int>> v;
	
	for (int i = 0;i < N;i++) {
		int p, q;
		cin >> p >> q;
		v.push_back({ p,q });
	}
	sort(v.begin(), v.end());
	map<int, int> dic;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<int, vector<int>, greater<int>> left;
	for (int i = 0, j = 0;i < v.size();i++) {
		while (!pq.empty()) {
			if (v[i].first >= pq.top().first) {
				left.push(pq.top().second);
				pq.pop();
			}
			else
				break;
		}
		if (left.empty()) {
			dic[j]++;
			pq.push({ v[i].second,j++ });
		}
		else {
			int tmp = left.top();
			pq.push({ v[i].second,tmp });
			dic[tmp]++;
			left.pop();
		}
	}
	cout << dic.size() << endl;
	for (auto i : dic) {
		cout << i.second << " ";
	}
}