#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 8

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int N, M;
int result;
int map[MAX][MAX];
int tmp[MAX][MAX];

void bfs() {
	int aftermap[MAX][MAX];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			aftermap[i][j] = tmp[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (aftermap[i][j] == 2)
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];

			if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
				if (aftermap[newX][newY] == 0) {
					aftermap[newX][newY] = 2;
					q.push({ newX,newY });
				}

			}
		}
	}

	int empty = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (aftermap[i][j] == 0)
				empty++;
		}
	}

	result = max(result, empty);
}

void makewall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				makewall(cnt + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == 0) {
				for (int k = 0;k < N;k++) {
					for (int l = 0;l < M;l++) {
						tmp[k][l] = map[k][l];
					}
				}

				tmp[i][j] = 1;
				makewall(1);
				tmp[i][j] = 0;
			}
		}
	}

	cout << result;
}