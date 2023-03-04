#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100001

int N;
bool visit[MAX];
int parent[MAX];
vector<int> v[MAX];

void Solution(int start) {
	visit[start] = true;

	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i];

		if (!visit[next]) {
			parent[next] = start;
			Solution(next);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0;i < N-1;i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	Solution(1);

	for (int i = 2;i <= N;i++) {
		cout << parent[i] << endl;
	}
}