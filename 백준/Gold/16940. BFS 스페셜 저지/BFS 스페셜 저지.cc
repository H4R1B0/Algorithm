#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
vector<int> v[MAX];
bool visit[MAX];

int main() {
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> B(N + 1);
	vector<int> order(N + 1);

	for (int i = 1;i <= N;i++) {
		cin >> B[i];
		order[B[i]] = i;
	}

	for (int i = 1;i <= N;i++) {
		sort(v[i].begin(), v[i].end(), [&](const int& a, const int& b) {
			return order[a] < order[b];
			});
	}

	vector<int> bfs_order;
	bfs_order.push_back(0);
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		bfs_order.push_back(cur);

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				q.push(next);
				visit[next] = true;
			}
		}
	}

	if (bfs_order == B)
		cout << 1;
	else
		cout << 0;
}