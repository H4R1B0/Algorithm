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
#define MAX 123456+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
char WS[MAX];
vector<long long> g[MAX];
long long numbers[MAX];

long long dfs(int node) {
	long long cnt = 0;
	for (int i = 0;i < g[node].size();i++) {
		cnt += dfs(g[node][i]);
	}

	if (WS[node] == 'W') {
		cnt = cnt - numbers[node];
		if (cnt < 0)
			return 0;
		else
			return cnt;
	}
	else
		return cnt + numbers[node];
}

int main() {
	cin >> N;
	for (int i = 2;i <= N;i++) {
		char t;
		long long a, p;
		cin >> t >> a >> p;
		WS[i] = t;
		numbers[i] = a;
		g[p].push_back(i);
	}
	WS[1] = 'S';
	numbers[1] = 0;
	cout << dfs(1);
}