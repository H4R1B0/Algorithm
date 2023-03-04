#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 64+1

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, Q;
int map[MAX][MAX];
int tmp[MAX][MAX];
bool checkMelt[MAX][MAX], visit[MAX][MAX];

int getSum() {
	int sum = 0;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			sum += map[i][j];
	return sum;
}

int dfs(int x, int y) {
	visit[x][y] = true;
	int ret = 1;
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (!visit[nx][ny] && map[nx][ny] > 0)
				ret += dfs(nx, ny);
	}
	return ret;
}

int getBiggest() {
	int ret = 0;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			if (map[i][j] > 0 && !visit[i][j])
				ret = max(ret, dfs(i, j));
	return ret;
}

void rotate(int x, int y, int L) {
	for (int i = 0;i < L;i++) {
		for (int j = 0;j < L;j++) {
			tmp[i][j] = map[x + L - 1 - j][y + i];
		}
	}
	for (int i = 0;i < L;i++) {
		for (int j = 0;j < L;j++) {
			map[x + i][y + j] = tmp[i][j];
		}			
	}		
}

void Solve(int L) {
	L = 1 << L;

	for (int i = 0;i < N;i += L) {
		for (int j = 0;j < N;j += L) {
			rotate(i, j, L);
		}
	}

	memset(checkMelt, false, sizeof(checkMelt));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (map[i][j] == 0)
				continue;
			int cnt = 0;
			for (int k = 0;k < 4;k++) {
				int nx = i + xd[k];
				int ny = j + yd[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] > 0)
						cnt++;
				}
			}
			if (cnt < 3)
				checkMelt[i][j] = true;
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (checkMelt[i][j])
				map[i][j]--;
		}
	}
}

int main() {
	cin >> N >> Q;
	N = 1 << N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	while (Q--) {
		int L;
		cin >> L;
		Solve(L);
	}

	cout << getSum() << endl;;
	cout << getBiggest() << endl;;
}