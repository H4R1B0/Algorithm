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

int N;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[y] = x;
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int a;
			cin >> a;
			if (j > i)
				v.push_back({ a,{i,j} });
		}
	}
	long long result = 0;
	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int from = v[i].second.first;
		int to = v[i].second.second;

		if (Find(from) != Find(to)) {
			Union(from, to);
			result += cost;
		}
	}
	cout << result;
}