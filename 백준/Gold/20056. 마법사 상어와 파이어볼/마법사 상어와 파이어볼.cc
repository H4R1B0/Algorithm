#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 55
#define endl '\n'

int xd[] = { -1,-1,0,1,1,1,0,-1 };
int yd[] = { 0,1,1,1,0,-1,-1,-1 };

struct FIREBALL
{
	int x, y, m, s, d;
};

int N, M, K;
vector<FIREBALL> MAP[MAX][MAX];
vector<FIREBALL> FireBall;

void dfs(int cnt) {
	if(cnt == 0)
		return;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			MAP[i][j].clear();
		}
	}
	for (int i = 0; i < FireBall.size(); i++) {
		int x = FireBall[i].x;
		int y = FireBall[i].y;
		int m = FireBall[i].m;
		int s = FireBall[i].s;
		int d = FireBall[i].d;

		int Move = s % N;
		int nx = x + xd[d] * Move;
		int ny = y + yd[d] * Move;
		if (nx >= N) nx -= N;
		if (ny >= N) ny -= N;
		if (nx < 0) nx += N;
		if (ny < 0) ny += N;
		MAP[nx][ny].push_back({ nx,ny,m,s,d });
		FireBall[i].x = nx;
		FireBall[i].y = ny;
	}

	vector<FIREBALL> tmp;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j].size() == 0)
				continue;
			if (MAP[i][j].size() == 1) {
				tmp.push_back(MAP[i][j][0]);
			}
			else {
				int sum_m = 0, sum_s = 0;
				int even_cnt = 0, odd_cnt = 0;
				for (int k = 0;k < MAP[i][j].size();k++) {
					sum_m += MAP[i][j][k].m;
					sum_s += MAP[i][j][k].s;
					if (MAP[i][j][k].d % 2 == 0)
						even_cnt++;
					else
						odd_cnt++;
				}
				int m = sum_m / 5;
				if (m == 0)
					continue;
				int s = sum_s / MAP[i][j].size();
				if (even_cnt == MAP[i][j].size() || odd_cnt == MAP[i][j].size()) {
					tmp.push_back({ i,j,m,s,0 });
					tmp.push_back({ i,j,m,s,2 });
					tmp.push_back({ i,j,m,s,4 });
					tmp.push_back({ i,j,m,s,6 });
				}
				else {
					tmp.push_back({ i,j,m,s,1 });
					tmp.push_back({ i,j,m,s,3 });
					tmp.push_back({ i,j,m,s,5 });
					tmp.push_back({ i,j,m,s,7 });
				}
			}		
		}
	}
	FireBall = tmp;
	dfs(cnt - 1);
}

int main(void) {
	//cout << ((-2) % 3+3);

	cin >> N >> M >> K;
	for (int i = 0;i < M;i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		FireBall.push_back({ r-1, c-1, m, s, d });
		MAP[r-1][c-1].push_back({ r-1, c-1, m, s, d });
	}
	dfs(K);

	int answer = 0;
	for (int i = 0; i < FireBall.size(); i++)
		answer += FireBall[i].m;
	cout << answer;
}