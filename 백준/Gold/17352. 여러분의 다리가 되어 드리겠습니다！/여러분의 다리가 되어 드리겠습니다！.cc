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
#define MAX 300000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int parent[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	for (int i = 0;i < N - 2;i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 2;i <= N;i++) {
		if (Find(1) != Find(i)) {
			cout << 1 << " " << i;
			return 0;
		}
	}
}