#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 5+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N;
int Max = -INF, Min = INF;
char map[MAX][MAX];

void dfs(int x, int y, int num, char c) {
	if (x == N && y == N) {
		Max = max(Max, num);
		Min = min(Min, num);
		return;
	}

	for (int i = 0;i < 2;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (map[nx][ny] == '+') {
				dfs(nx, ny, num, '+');
			}
			else if (map[nx][ny] == '-') {
				dfs(nx, ny, num, '-');
			}
			else if (map[nx][ny] == '*') {
				dfs(nx, ny, num, '*');
			}
			else {
				int result = 0;
				if (c == '+') {
					result = num + (map[nx][ny] - '0');
				}
				else if (c == '-') {
					result = num - (map[nx][ny] - '0');
				}
				else if (c == '*') {
					result = num * (map[nx][ny] - '0');
				}
				dfs(nx, ny, result, map[nx][ny]);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 1, map[1][1] - '0', map[1][1]);

	cout << Max << " " << Min;
}