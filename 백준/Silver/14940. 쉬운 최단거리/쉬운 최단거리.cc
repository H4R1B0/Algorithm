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
int result[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ Start.first,Start.second });
	visit[Start.first][Start.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && map[nx][ny]) {
					visit[nx][ny] = true;
					result[nx][ny] = result[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				Start = { i,j };
				map[i][j] = 0;
			}	
		}
	}
	bfs();
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (result[i][j] == 0 && map[i][j] == 0)
				cout << 0 << " ";
			else if (result[i][j] != 0 && map[i][j] != 0)
				cout << result[i][j] << " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
	}
}