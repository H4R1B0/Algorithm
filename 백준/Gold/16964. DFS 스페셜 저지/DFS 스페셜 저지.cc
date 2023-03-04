#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
vector<int> v[MAX];
bool check[MAX];
vector<int> dfs_order;

void dfs(int x) {
	if (check[x] == true) {
		return;
	}
	dfs_order.push_back(x);
	check[x] = true;

	for (int i : v[x]) {
		if (check[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> D(N + 1);
	vector<int> order(N + 1);

	for (int i = 1;i <= N;i++) {
		cin >> D[i];
		order[D[i]] = i;
	}

	for (int i = 1;i <= N;i++) {
		sort(v[i].begin(), v[i].end(), [&](const int& a, const int& b) {
			return order[a] < order[b];
			});
	}
	
	dfs_order.push_back(0);
	dfs(1);

	if (dfs_order == D)
		cout << 1;
	else
		cout << 0;
}