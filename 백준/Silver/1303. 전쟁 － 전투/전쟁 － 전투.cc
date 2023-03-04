#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
string map[MAX];
int B_sum, W_sum;
bool visit[MAX][MAX];

void bfs(int i, int j) {
	char c = map[i][j];
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && map[nx][ny] == c) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
	if (c == 'W') {
		W_sum += cnt * cnt;
	}
	else
		B_sum += cnt * cnt;
}

int main() {
	cin >> M >> N;
	for (int i = 0;i < N;i++)
		cin >> map[i];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!visit[i][j]) {
				bfs(i, j);
			}
		}
	}
	cout << W_sum << " " << B_sum << endl;
}