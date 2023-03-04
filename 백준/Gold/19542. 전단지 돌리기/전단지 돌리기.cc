#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N, S, D;
int result;
int cnt[MAX];
vector<int> v[MAX];
bool visit[MAX];

int dfs(int cur) {
	int dep = 0;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];
		if (!visit[next]) {
			visit[next] = true;
			dep = dfs(next);
			cnt[cur] = max(cnt[cur], dep);
		}
	}
	return max(cnt[cur], dep) + 1;
}

void  go(int cur) {
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i];
		if (cnt[next]>=D && !visit[next]) {
			visit[next] = true;
			result++;
			go(next);
		}
	}
}

int main() {
	cin >> N >> S >> D;
	for(int i=0;i<N-1;i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visit[S] = true;
	dfs(S);

	memset(visit, false, sizeof(visit));
	visit[S] = true;
	go(S);
	
	cout << result*2;
}