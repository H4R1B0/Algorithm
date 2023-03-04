#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 17
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int boom_cnt = 0;
int tmp_cnt = 0;
char map[12][6];
bool visit[12][6];
vector<pair<int, int>> boom_tmp, boom_vec;

void dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0;i < 4;i++) {

		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
			continue;
		if (map[nx][ny] == '.')
			continue;
		if (visit[nx][ny])
			continue;
		if (map[nx][ny] != map[x][y])
			continue;

		tmp_cnt++;
		boom_tmp.push_back({ nx,ny });
		dfs(nx, ny);
	}
}

int main(void)
{
	for (int i = 0;i < 12;i++) {
		for (int j = 0;j < 6;j++) {
			cin >> map[i][j];
		}
	}

	bool flag = true;
	int result = 0;
	while (flag) {

		flag = false;

		memset(visit, false, sizeof(visit));
		boom_vec.clear();

		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 6;j++) {
				if (!visit[i][j] && map[i][j] != '.') {
					tmp_cnt = 1;
					boom_tmp.push_back({ i,j });
					dfs(i, j);

					if (tmp_cnt >= 4) {
						flag = true;
						for (int i = 0;i < boom_tmp.size();i++)
							boom_vec.push_back(boom_tmp[i]);
					}
					boom_tmp.clear();
				}
			}
		}
		for (int i = 0;i < boom_vec.size();i++) {
			int x = boom_vec[i].first;
			int y = boom_vec[i].second;

			map[x][y] = '.';
		}

		for (int i = 10;i >= 0;i--) {
			for (int j = 0;j < 6;j++) {
				if (map[i][j] == '.')
					continue;
				int tmp = i;

				while (1) {
					if (tmp == 11 || map[tmp + 1][j] != '.')
						break;
					map[tmp + 1][j] = map[tmp][j];
					map[tmp][j] = '.';
					tmp++;
				}
			}
		}
		if (flag)
			result++;
		else
			flag = false;
	}
	cout << result;
}