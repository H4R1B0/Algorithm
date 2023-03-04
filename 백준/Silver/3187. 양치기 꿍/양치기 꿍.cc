#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 250+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int R, C;
int result_v, result_k;
string map[MAX];
bool visit[MAX][MAX];

void bfs(int a,int b) {
	int v_cnt = 0, k_cnt = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == 'v')
			v_cnt++;
		else if (map[x][y] == 'k')
			k_cnt++;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!visit[nx][ny] && map[nx][ny] != '#') {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
	if (k_cnt > v_cnt)
		result_k += k_cnt;
	else
		result_v += v_cnt;
}

int main() {
	cin >> R >> C;
	for (int i = 0;i < R;i++)
		cin >> map[i];

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				bfs(i, j);
			}
		}
	}
	cout << result_k << " " << result_v;
}