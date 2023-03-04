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
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX][2];
pair<int, int> Start, End;

int bfs() {
	//x,y,cnt,벽 부슨 횟수
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {Start.first,Start.second},{0,0} });
	visit[Start.first][Start.second][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int kcnt = q.front().second.second;
		q.pop();

		if (x == End.first && y == End.second) {
			return cnt;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (map[nx][ny] == 0) {
					if (!visit[nx][ny][kcnt]) {
						visit[nx][ny][kcnt] = true;
						q.push({ {nx,ny}, {cnt + 1,kcnt} });
					}
				}
				else if (map[nx][ny] == 1) {
					if (kcnt < 1) {
						if (!visit[nx][ny][kcnt+1]) {
							visit[nx][ny][kcnt+1] = true;
							q.push({ {nx,ny}, {cnt + 1,kcnt+1} });
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	cin >> Start.first >> Start.second;
	cin >> End.first >> End.second;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs();
}