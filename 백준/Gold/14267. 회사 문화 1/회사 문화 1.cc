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
#define MAX 100000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
vector<int> v[MAX];
int compliment[MAX];

void dfs(int node) {
	for (int i = 0;i < v[node].size();i++) {
		int next = v[node][i];
		compliment[next] += compliment[node];
		dfs(next);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		int a;
		cin >> a;
		v[a].push_back(i);
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		compliment[a] += b;
	}
	dfs(1);
	for (int i = 1;i <= N;i++)
		cout << compliment[i] << " ";
}