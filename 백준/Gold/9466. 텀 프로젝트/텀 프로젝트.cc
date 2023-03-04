#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


int T, N, cnt;
int student[MAX];
bool visit[MAX];
bool done[MAX];

void dfs(int start) {
	visit[start] = true;

	int next = student[start];
	if (!visit[next])
		dfs(next);

	else if (!done[next]) {
		for (int i = next; i != start; i = student[i])
			cnt++;
		cnt++;
	}
	done[start] = true;
}

int main() {
	cin >> T;
	while (T--) {
		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));
		
		cin >> N;
		for (int i = 1;i <= N;i++)
			cin >> student[i];

		cnt = 0;
		for (int i = 1;i <= N;i++) {
			if (!visit[i])
				dfs(i);
		}
		cout << N - cnt << endl;
	}
}