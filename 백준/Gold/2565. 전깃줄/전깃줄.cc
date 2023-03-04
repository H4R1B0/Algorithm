#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
vector<pair<int, int>> v;
int dp[MAX];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.push_back({ 0,0 });
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1;i <= N;i++) {
		dp[i] = 1;
		for (int j = 1;j <= i;j++) {
			if (v[j].second < v[i].second && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
	int answer = 0;
	for (int i = 1;i <= N;i++)
		answer = max(answer, dp[i]);
	cout << N - answer;
}