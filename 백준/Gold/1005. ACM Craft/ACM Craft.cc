#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001

int N, K, D, W;
int Time[MAX];
int Result_Time[MAX];
int Entry[MAX];
vector<int> Build[MAX];

int main() {
	int T;
	cin >> T;
	for (int i = 0;i < T;i++) {
		memset(Time, 0, sizeof(Time));
		memset(Result_Time, 0, sizeof(Result_Time));
		memset(Entry, 0, sizeof(Entry));
		for (int i = 0; i < MAX; i++) Build[i].clear();

		cin >> N >> K;

		for (int j = 1;j <= N;j++) {
			cin >> Time[j];
		}

		for (int j = 0;j < K;j++) {
			int a, b;
			cin >> a >> b;
			Build[a].push_back(b);
			Entry[b]++;
		}
		cin >> W;


		queue<int> q;
		for (int j = 1;j <= N;j++) {
			if (Entry[j] == 0) {
				q.push(j);
				Result_Time[j] = Time[j];
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 0;j < Build[cur].size();j++) {
				int next = Build[cur][j];
				Result_Time[next] = max(Result_Time[next], Result_Time[cur] + Time[next]);
				Entry[next]--;

				if (Entry[next] == 0)
					q.push(next);
			}
		}
		cout << Result_Time[W] << endl;
	}
}