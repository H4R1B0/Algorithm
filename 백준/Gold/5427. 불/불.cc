#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> fire;
pair<int, int> Start;

int bfs() {
	queue<pair<int, int>> q;
	q.push(Start);

	int result = 0;
	while (!q.empty()) {
		int firesize = fire.size();
		for (int i = 0;i < firesize;i++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int j = 0;j < 4;j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if(nx>=0 && nx<N && ny >= 0 && ny < M)
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						fire.push({ nx,ny });
					}
			}
		}

		int qsize = q.size();
		for (int i = 0;i < qsize;i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == N - 1 || y == 0 || y == M - 1)
				return result + 1;

			for (int j = 0;j < 4;j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M)
					if (!visit[nx][ny] && map[nx][ny] != '*' && map[nx][ny]!='#') {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
			}
		}
		result++;
	}
	return -1;
}

int main(void)
{
	int T;
	cin >> T;
	while (T--) {

		while (!fire.empty())
			fire.pop();

		memset(visit, false, sizeof(visit));

		cin >> M >> N;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cin >> map[i][j];
				if (map[i][j] == '@')
					Start = { i,j };
				else if (map[i][j] == '*')
					fire.push({ i,j });
			}
		}
		int result = bfs();
		if (result == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;
	}	
}