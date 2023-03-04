#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int K, N, M;
//map<ll, bool> visit;
set<int> s;
vector<ll> numbers;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> v;
		vector<int> answer;
		priority_queue<int> max_pq;
		priority_queue<int,vector<int>,greater<int>> min_pq;
		for (int i = 1;i <= N;i++) {
			int a;
			cin >> a;
			if (max_pq.size() == min_pq.size()) {
				max_pq.push(a);
			}
			else {
				min_pq.push(a);
			}
			//cout << 1;
			if (!max_pq.empty() && !min_pq.empty()) {
				if (max_pq.top() > min_pq.top()) {
					int tmp1 = max_pq.top();
					int tmp2 = min_pq.top();
					max_pq.pop();
					min_pq.pop();
					max_pq.push(tmp2);
					min_pq.push(tmp1);
				}
			}

			if (i % 2 == 1) {
				answer.push_back(max_pq.top());
			}
		}
		cout << answer.size() << endl;
		for (int i = 0;i < answer.size();i++) {
			if (i>0 && i % 10 == 0)
				cout << endl;
			cout << answer[i] << " ";
		}
		cout << endl;
	}
}