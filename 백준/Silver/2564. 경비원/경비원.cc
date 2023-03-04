#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 2000
#define endl '\n'

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
int MAP[101][101];
int visit[101][101];

pair<int, int> getPos(int dir, int num) {
	if (dir == 1)
		return { 0,num };
	if (dir == 2)
		return { N-1,num };
	if (dir == 3)
		return { num,0 };
	if (dir == 4)
		return { num,M-1 };
}

int main(void) {
	cin >> M >> N;
	M++, N++;
	for (int i = 0;i < M;i++) {
		MAP[0][i] = 1;
		MAP[N-1][i] = 1;
	}
	for (int i = 0;i < N;i++) {
		MAP[i][0] = 1;
		MAP[i][M-1] = 1;
	}

	int T, sx, sy;
	vector<pair<int, int>> v;
	cin >> T;
	int a, b;
	while (T--) {		
		cin >> a >> b;
		v.push_back(getPos(a,b));
	}
	cin >> a >> b;
	sx = getPos(a, b).first;
	sy = getPos(a, b).second;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && MAP[nx][ny]==1) {
					visit[nx][ny] = visit[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	int answer = 0;
	for (auto i : v) {
		//cout << i.first << " " << i.second << endl;
		answer += visit[i.first][i.second] - visit[sx][sy];
	}
	cout << answer;
}