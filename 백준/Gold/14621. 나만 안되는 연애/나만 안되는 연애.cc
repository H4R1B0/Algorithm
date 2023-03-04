#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
char map[MAX];
int parent[MAX];
vector<pair<int, pair<int,int>>> v;

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
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		cin >> map[i];
		parent[i] = i;
	}
		
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	int result = 0;
	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int from = v[i].second.first;
		int to = v[i].second.second;

		if (Find(from) != Find(to) && map[from] != map[to]) {
			Union(from, to);
			result += cost;
		}
	}

	int cnt = 0;
	for (int i = 1;i <= N;i++)
		if (i == parent[i])
			cnt++;
	if (cnt == 1)
		cout << result;
	else
		cout<<-1;
}