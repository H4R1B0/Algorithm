#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 1001
#define endl '\n'

int N, M, R;
int MAP[301][301];

void dfs(int cnt) {
	if(cnt == 0)
		return;
	int depth = min(N, M) / 2 + min(N, M) % 2;
	for (int start = 0;start < depth;start++) {
		int r = start;
		int c = start;
		int pre = MAP[r][c];
		//왼
		while (r < N - 1 - start) {
			int next = MAP[r + 1][c];
			MAP[r + 1][c] = pre;
			pre = next;
			r++;
		}
		//아래
		while (c < M - 1 - start) {
			int nextVal = MAP[r][c + 1];
			MAP[r][c + 1] = pre;
			pre = nextVal;
			c++;
		}
		//오른
		while (r >= 1 + start) {
			int nextVal = MAP[r - 1][c];
			MAP[r - 1][c] = pre;
			pre = nextVal;
			r--;
		}
		//위
		while (c >= 1 + start) {
			int nextVal = MAP[r][c - 1];
			MAP[r][c - 1] = pre;
			pre = nextVal;
			c--;
		}
	}
	dfs(cnt - 1);
}

int main(void) {
	cin >> N >> M >> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}

	dfs(R);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
}