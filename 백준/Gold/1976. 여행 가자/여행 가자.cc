#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 201
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int parent[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}
void Union(int x,int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	cin >> N;
	cin >> M;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int connect;
			cin >> connect;
			if (connect) {
				Union(i, j);
			}
		}
	}

	int a, b;
	cin >> a;
	b = Find(a);

	for (int i = 1;i <= M;i++) {
		cin >> a;
		if (b != Find(a)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}