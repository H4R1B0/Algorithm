#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
int parent[MAX];
int enemy[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}
bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)
		return 0;
	if (x > y)
		parent[x] = y;
	else 
		parent[y] = x;
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		parent[i] = i;

	int answer = 1;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		a = Find(a), b = Find(b);
		if (a == b) {
			answer = 0;
		}
		enemy[a] ? Union(enemy[a], b) : enemy[a] = b;
		enemy[b] ? Union(enemy[b], a) : enemy[b] = a;
	}
	cout << answer;
}