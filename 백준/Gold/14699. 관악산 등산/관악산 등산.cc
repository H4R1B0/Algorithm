#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 5000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N, M;
int height[MAX];
int dp[MAX];
vector<int> v[MAX];

int dfs(int cur) {
	if (dp[cur] != 0)
		return dp[cur];
	for (int i = 0;i < v[cur].size();i++) {
		dp[cur] = max(dp[cur], dfs(v[cur][i]));
	}
	return ++dp[cur];
}

int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		cin >> height[i];

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		if(height[a] < height[b])
			v[a].push_back(b);
		else
			v[b].push_back(a);
	}

	for (int i = 1;i <= N;i++)
		cout << dfs(i) << endl;
}