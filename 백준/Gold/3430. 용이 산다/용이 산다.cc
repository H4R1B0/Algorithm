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


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<int> arr(M + 1, 1);
		for (int i = 0;i < M;i++) {
			cin >> arr[i];
		}

		vector<bool> emptyLake(N + 1,false);
		bool flag = true;
		vector<vector<int>> cache(N + 1);
		vector<int> Time(M, -1);
		for (int i = M-1;i >= 0;i--) {
			if (arr[i]) {
				Time[i] = arr[i];
				cache[arr[i]].push_back(i);
			}
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1;i <= N;i++) {
			if (cache[i].size()) {
				//cout << cache[i].back()<<endl;
				pq.push(cache[i].back());
				cache[i].pop_back();
			}
		}
		//cout << pq.size() << endl;
		vector<int> answer;
		for (int i = 0;i < M;i++) {
			//cout << pq.size() << endl;
			if (arr[i]) {
				if (!emptyLake[arr[i]]) {
					flag = false;
					break;
				}
				emptyLake[arr[i]] = false;
				if (cache[arr[i]].size()) {
					pq.push(cache[arr[i]].back());
					cache[arr[i]].pop_back();
				}
			}
			else {
				if (!pq.empty()) {
					int cur = pq.top();
					pq.pop();
					answer.push_back(Time[cur]);
					emptyLake[Time[cur]] = true;
				}
				else {
					answer.push_back(0);
				}
			}
		}

		if (!flag) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (auto i : answer) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}