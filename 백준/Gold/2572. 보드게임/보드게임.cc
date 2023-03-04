#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
char Card[MAX];
int Score[MAX][501];
vector<pair<int, char>> v[MAX];

int dfs(int cur, int idx) {
	if (idx == N + 1)
		return 0;
	
	if (Score[idx][cur] != -1)
		return Score[idx][cur];

	Score[idx][cur] = 0;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i].first;
		char nc = v[cur][i].second;

		Score[idx][cur] = max(Score[idx][cur], dfs(next, idx + 1) + (Card[idx] == nc ? 10 : 0));
	}
	return Score[idx][cur];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> Card[i];
	cin >> M >> K;
	for (int i = 0;i < K;i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	memset(Score, -1, sizeof(Score));
	cout << dfs(1, 1);
}