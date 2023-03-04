#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>

#define endl "\n"
#define MAX 3000+1
#define INF LLONG_MAX
#define ll long long
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Start;

void bfs() {
	queue<pair<pair<int,int>, int>> q;
	q.push({ {Start.first,Start.second},0 });
	visit[Start.first][Start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (map[x][y] >= 3 && map[x][y] <= 5) {
			cout << "TAK" << endl;
			cout << cnt;
			return;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == 1)
					continue;
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ { nx,ny},cnt+1 });
				}
			}
		}
	}
	cout << "NIE";
}

int main(void) {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < M;j++) {
			map[i][j] = str[j] - '0';
			if (map[i][j] == 2)
				Start = { i,j };
		}
	}
	bfs();

}
