#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int xd[] = { -2,-1,1,2,2,1,-1,-2 };
int yd[] = { 1,2,2,1,-1,-2,-2,-1 };

int N, M;
int parent[MAX];
int g[MAX][MAX];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++)
		parent[i] = i;
	int sum = 0;
	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.length();j++) {
			if (s[j] == '0') {
				g[i][j] = 0;
			}
			else if (s[j] >= 'a' && s[j] <= 'z') {
				g[i][j] = s[j] - 'a' + 1;
				sum += g[i][j];
			}
			else if (s[j] >= 'A' && s[j] <= 'Z') {
				g[i][j] = s[j] - 'A' + 27;
				sum += g[i][j];
			}
			if(g[i][j])
				v.push_back({ g[i][j],{i,j} });
		}
	}
	sort(v.begin(), v.end());

	int ans = 0;
	int cnt = 0;
	for (int i = 0;i < v.size();i++) {
		if (cnt == N - 1)
			break;

		int cost = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (Find(x) != Find(y)) {
			ans += cost;
			Union(Find(x), Find(y));
			cnt++;
		}
	}

	if (cnt != N - 1) {
		cout << -1;
		return 0;
	}
	cout << sum - ans;
}