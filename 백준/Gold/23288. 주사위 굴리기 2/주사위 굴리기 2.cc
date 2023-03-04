#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 20+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
int result;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dice[7] = { 0, 1, 2, 3, 4, 5, 6 };


int ReverseDir(int d) {
	return (d + 2) % 4;
}

void UpdateDiceState(int d) {
	int d1 = dice[1];
	int d2 = dice[2];
	int d3 = dice[3];
	int d4 = dice[4];
	int d5 = dice[5];
	int d6 = dice[6];

	switch (d) {
	case 0:
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
		break;
	case 1:
		dice[1] = d5;
		dice[5] = d6;
		dice[6] = d2;
		dice[2] = d1;
		break;
	case 2:
		dice[1] = d3;
		dice[3] = d6;
		dice[6] = d4;
		dice[4] = d1;
		break;
	case 3:
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
		dice[5] = d1;
		break;
	}
}

int ChangeDir(int dir, int A, int B) {
	if (A > B) {
		return (dir + 3) % 4;
	}
	else if (A < B) {
		return (dir + 1) % 4;
	}
	return dir;
}

void GetScore(int a, int b) {
	memset(visit, false, sizeof(visit));

	int cnt = 1;

	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (map[nx][ny] == map[x][y] && !visit[nx][ny]) {
					visit[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
	}
	result += (map[a][b] * cnt);
}


void Solution() {
	int x = 1;
	int y = 1;
	int dir = 0;
	for (int i = 0;i < K;i++) {
		int nx = x + xd[dir];
		int ny = y + yd[dir];
		if (nx<1 || nx>N || ny<1 || ny>M) {
			dir = ReverseDir(dir);
			nx = x + xd[dir];
			ny = y + yd[dir];
		}
		GetScore(nx, ny);
		UpdateDiceState(dir);
		dir = ChangeDir(dir, dice[6], map[nx][ny]);
		x = nx;
		y = ny;
	}
	cout << result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> map[i][j];
		}
	}
	Solution();
}