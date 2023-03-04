#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
int parent[MAX];
int fee[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (fee[x] < fee[y])
		parent[y] = x;
	else
		parent[x] = y;
}

int main(void)
{
	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 1;i <= N;i++) {
		cin >> fee[i];
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	int ans = 0;
	for (int i = 1;i <= N;i++) {
		if (parent[i] == i)
			ans += fee[i];
	}
	if (K < ans)
		cout << "Oh no" << endl;
	else
		cout << ans << endl;
}