#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 32001

int N,M;
int Entry[MAX];
vector<int> v[MAX];

void Solution() {
	queue<int> q;

	for (int i = 1;i <= N;i++) {
		if (Entry[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			Entry[next]--;

			if (Entry[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;

		Entry[b]++;
		v[a].push_back(b);
	}
	Solution();
	
}