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
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return false;
	if (x == -1 || x < y)
		parent[y] = x;
	else if (y == -1 || x > y)
		parent[x] = y;
	return true;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++)
		parent[i] = i;
	for (int i = 0;i < K;i++) {
		int a;
		cin >> a;
		parent[a] = -1;
	}
	
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}

	int result = 0;
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (Union(x, y))
			result += cost;
	}
	cout << result;
}