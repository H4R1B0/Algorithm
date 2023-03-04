#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 250+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int R, C;
char map[MAX][MAX];
bool visit[MAX][MAX];
int o_cnt, v_cnt;

void bfs(int a, int b) {
	int num1 = 0; //양
	int num2 = 0; //늑대

	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == 'o')
			num1++;
		else if (map[x][y] == 'v')
			num2++;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!visit[nx][ny] && map[nx][ny] != '#') {
					q.push({nx,ny});
					visit[nx][ny] = true;
				}
			}
		}
	}
	if (num1 > num2) {
		v_cnt -= num2;
	}
	else {
		o_cnt -= num1;
	}
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o')
				o_cnt++;
			if (map[i][j] == 'v')
				v_cnt++;
		}
	}

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (map[i][j] != '#' && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}
	cout << o_cnt << " " << v_cnt;
}