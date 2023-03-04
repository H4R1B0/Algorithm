#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K, Len;
char map[MAX][MAX];
string word;
int visit[MAX][MAX][81];

int dfs(int x, int y, int idx) {
	if (visit[x][y][idx] != -1)
		return visit[x][y][idx];
	if (idx >= Len)
		return 1;

	visit[x][y][idx] = 0;
	for (int i = 0;i < 4;i++) {
		for (int k = 1;k <= K;k++) {
			int nx = x + xd[i]*k;
			int ny = y + yd[i]*k;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == word[idx]) {
					visit[x][y][idx] += dfs(nx, ny, idx + 1);
				}
			}
		}
	}
	return visit[x][y][idx];
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}
	cin >> word;
	Len = word.length();
	memset(visit, -1, sizeof(visit));

	int result = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == word[0])
				result += dfs(i, j, 1);
		}
	}
	cout << result;
}