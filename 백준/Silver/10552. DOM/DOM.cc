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
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, P;
int cnt;
int v[MAX];
bool visit[MAX];

void dfs(int ch) {
	if (visit[ch]) {
		cnt = -1;
		return;
	}		
	else if(v[ch]!=0){
		visit[ch] = true;
		cnt++;
		dfs(v[ch]);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> P;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		if (v[b] == 0)
			v[b] = a;
	}
	dfs(P);
	cout << cnt;
}