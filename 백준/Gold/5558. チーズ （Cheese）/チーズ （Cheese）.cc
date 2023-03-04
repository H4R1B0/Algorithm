#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int result, idx = 1;
char map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start;

void bfs(int a, int b) {
	//x,y,cnt,K_cnt
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b}, 0 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visit[nx][ny] || map[nx][ny] == 'X')
				continue;
			if ('1' <= map[nx][ny] && map[nx][ny] <= '9') {
				if (idx >= map[nx][ny] - '0') {
					idx++;
					map[nx][ny] = '.';
					result += (cnt + 1);
					Start = { nx,ny };
					return;
				}
			}
			q.push({ {nx, ny}, cnt + 1 });
			visit[nx][ny] = true;
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S')
				Start = { i,j };
		}
	}

	for (int i = 0;i < K;i++) {
		memset(visit, false, sizeof(visit));
		bfs(Start.first, Start.second);
	}
	cout << result;
}