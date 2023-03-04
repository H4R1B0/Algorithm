#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
int endP, startP, Max;
vector<int> answer;
vector<pair<int, int>> v[MAX];
bool visit[MAX];

void dfs(int start, int len) {
	if (visit[start])
		return;
	visit[start] = true;
	if (Max < len) {
		Max = len;
		endP = start;
	}
	for (int i = 0;i < v[start].size();i++) {
		dfs(v[start][i].first, len + v[start][i].second);
	}
}
void dfs2(int start, int len) {
	if (visit[start])
		return;
	visit[start] = true;
	if (Max < len) {
		Max = len;
		startP = start;
	}
	for (int i = 0;i < v[start].size();i++) {
		dfs2(v[start][i].first, len + v[start][i].second);
	}
}
void dfs3(int start, int len) {
	if (visit[start])
		return;
	visit[start] = true;
	if (Max < len) {
		Max = len;
	}
	for (int i = 0;i < v[start].size();i++) {
		dfs3(v[start][i].first, len + v[start][i].second);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	Max = 0;
	memset(visit, false, sizeof(visit));
	//cout << endP;
	dfs2(endP, 0);

	int answer=0;
	Max = 0;
	memset(visit, false, sizeof(visit));
	visit[endP] = true;
	dfs3(startP, 0);
	answer = max(answer, Max);
	Max = 0;
	memset(visit, false, sizeof(visit));
	visit[startP] = true;
	dfs3(endP, 0);
	answer = max(answer, Max);
	cout << answer;
}