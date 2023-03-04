#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
int arr[MAX];
map<int, int> hm;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<vector<int>> v(N + 1);
	vector<int> before(N + 1, -1);
	vector<int> stk(N + 1);
	for (int i = 1;i <= N;i++) {
		string s;
		cin >> s;
		arr[i] = 0;
		for (int j = 0;j < K;j++) {
			arr[i] <<= 1;
			arr[i] |= (s[j] - '0');
		}
		//cout << arr[i] << endl;
		hm[arr[i]] = i;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 0;j < K;j++) {
			int num = arr[i] ^ (1 << j);
			auto it = hm.find(num);
			if (it != hm.end()) {
				v[i].push_back(it->second);
			}
		}
	}

	cin >> M;
	int A = 1, B;
	queue<int> q;
	q.push(1);
	before[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : v[cur]) {
			if (before[next] == -1) {
				before[next] = cur;
				q.push(next);
			}
		}
	}
	while(M--) {
		cin >> B;
		if (before[B] == -1)
			cout << -1 << endl;
		else {
			int pos = 0;
			for (int i = B;i != 1;i = before[i])
				stk[pos++] = i;
			cout << 1 << " ";
			while (pos--)
				cout << stk[pos] << " ";
			cout << endl;
		}
	}
}