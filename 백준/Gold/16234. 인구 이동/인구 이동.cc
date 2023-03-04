#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 51
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, L, R;
int map[MAX][MAX];
bool visit[MAX][MAX];
bool check = true;

bool check_side(int x, int y) {
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (abs(map[x][y] - map[nx][ny]) >= L && abs(map[x][y] - map[nx][ny]) <= R) {
				return true;
			}
		}
	}
	return false;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q, nq;
	q.push({ x,y });
	nq.push({ x,y });
	visit[x][y] = true;

	int cnt = 0;
	int sum = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		sum += map[cx][cy];
		cnt += 1;

		for (int i = 0;i < 4;i++) {
			int nx = cx + xd[i];
			int ny = cy + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny]) {
				if (abs(map[cx][cy] - map[nx][ny]) >= L && abs(map[cx][cy] - map[nx][ny]) <= R) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					nq.push({ nx,ny });
				}
			}
		}
	}
	
	int value = sum / cnt;

	while (!nq.empty()) {
		int a = nq.front().first;
		int b = nq.front().second;
		nq.pop();
		map[a][b] = value;
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> map[i][j];
	
	int day = 0;
	while (check) {
		check = false;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (visit[i][j] == 0 && check_side(i, j) == true) {
					bfs(i, j);
					check = true;
				}
			}
		}
		if (check == true)
			day++;
		memset(visit, false, sizeof(visit));
	}

	cout << day;
}