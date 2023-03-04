#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, idx;
int node[MAX];
int low[MAX];
int high[MAX];
pair<int, int> tree[MAX];

void dfs(int num, int cnt) {
	if (tree[num].first >= 0)
		dfs(tree[num].first, cnt + 1);

	low[cnt] = min(low[cnt], idx);
	high[cnt] = max(high[cnt], idx++);

	if (tree[num].second > 0)
		dfs(tree[num].second, cnt + 1);
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < MAX;i++)
		low[i] = INF;

	for (int i = 0;i < N;i++) {
		int parent, child1, child2;
		cin >> parent >> child1 >> child2;

		node[parent]++;

		if (child1 != -1)
			node[child1]++;
		if (child2 != -1)
			node[child2]++;
		tree[parent] = { child1,child2 };
	}

	int root = 0;
	for (int i = 1;i <= N;i++) {
		if (node[i] == 1)
			root = i;
	}

	idx = 1;
	dfs(root, 1);

	int result = high[1] - low[1] + 1;
	int level = 1;
	for (int i = 2; i <= N; i++) {
		int temp = high[i] - low[i] + 1;
		if (temp > result) {
			result = temp;
			level = i;
		}
	}

	cout << level << " " << result << endl;
}