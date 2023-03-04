#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 10+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int len;
string s;
char g[MAX][MAX];
map<string, int> visit;

int dfs(int x, int y, int idx) {
	if (idx == len - 1)
		return 1;
	int ret = 0;
	for (int i = 0;i < 8;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx < 1)
			nx = N;
		if (nx > N)
			nx = 1;
		if (ny < 1)
			ny = M;
		if (ny > M)
			ny = 1;
		if (g[nx][ny] == s[idx + 1])
			ret += dfs(nx, ny, idx + 1);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> g[i][j];
		}
	}
	for (int k = 0;k < K;k++) {
		cin >> s;		
		if (!visit[s]) {
			len = s.length();
			int cnt = 0;
			for (int i = 1;i <= N;i++) {
				for (int j = 1;j <= M;j++) {
					if (g[i][j] == s[0])
						cnt += dfs(i, j, 0);
				}
			}
			visit[s] = cnt;
		}
		cout << visit[s] << endl;
	}
}