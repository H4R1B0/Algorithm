#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 110

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

struct info
{
	int s, d, z;
};

int R, C, M;
vector<info> MAP[MAX][MAX];

bool cmp(info a, info b) {
	return a.z < b.z;
}

int reverseDir(int dir) {
	if (dir == 0 || dir == 1)
		return 1 - dir;
	if (dir == 2 || dir == 3)
		return 5 - dir;
}

int main(void) {
	cin >> R >> C >> M;
	for (int i = 0;i < M;i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		if (d <= 2)
			s %= (R - 1) * 2;
		else
			s %= (C - 1) * 2;
		MAP[r][c].push_back({ s,d-1,z });
	}
	int cur = 1;
	int answer = 0;
	while (cur <= C) {	
		vector<info> tmpMAP[MAX][MAX];
		for (int i = 1;i <= R;i++) {
			if (MAP[i][cur].size() == 0)
				continue;
			else {
				answer += MAP[i][cur][0].z;
				MAP[i][cur].erase(MAP[i][cur].begin());
				break;
			}
		}

		for (int i = 1;i <= R;i++) {
			for (int j = 1;j <= C;j++) {
				for (int shark = 0;shark < MAP[i][j].size();shark++) {
					int x = i;
					int y = j;
					int dist = MAP[i][j][shark].s;
					int dir = MAP[i][j][shark].d;
					int size = MAP[i][j][shark].z;
					while (dist--) {
						x += xd[dir];
						y += yd[dir];
						if (x >= 1 && x <= R && y >= 1 && y <= C) {
							continue;
						}
						else {
							dir = reverseDir(dir);
							x += xd[dir] * 2;
							y += yd[dir] * 2;
						}
					}
					tmpMAP[x][y].push_back({ MAP[i][j][shark].s ,dir,size });
				}
			}
		}
		for (int i = 1;i <= R;i++) {
			for (int j = 1;j <= C;j++) {
				MAP[i][j].clear();
				if (tmpMAP[i][j].size()) {
					info tmp = tmpMAP[i][j][0];
					for (int k = 0;k < tmpMAP[i][j].size();k++) {
						if (tmp.z < tmpMAP[i][j][k].z) {
							tmp = tmpMAP[i][j][k];
						}
					}
					MAP[i][j].push_back(tmp);
				}
			}
		}
		cur++;
	}
	cout << answer;
}