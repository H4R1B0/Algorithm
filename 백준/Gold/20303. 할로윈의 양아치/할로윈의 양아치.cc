#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 30000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
int parent[MAX];
int person[MAX];
int dp[MAX];

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

	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
		person[i] = 1;
		cin >> arr[i];
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1;i <= N;i++) {
		if (i == parent[i])
			continue;
		int p = Find(i);
		arr[p] += arr[i];
		person[p] += person[i];
	}
	for (int i = 1;i <= N;i++) {
		if (i == parent[i]) {
			for (int j = K-1;j - person[i] >= 0;j--) {
				dp[j] = max(dp[j], dp[j - person[i]] + arr[i]);
			}
		}
	}
	cout << dp[K - 1];
}