#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 20+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, result = INF;
char map[MAX][MAX];
vector<pair<int, int>> Coin;

bool Check(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return true;
	return false;
}

void Move(int x, int y, int xx, int yy, int cnt, int dir) {
	if (result < cnt)
		return;
	if (cnt > 10) {
		result = min(result, cnt);
		return;
	}

	int nx = x + xd[dir];
	int ny = y + yd[dir];
	int nxx = xx + xd[dir];
	int nyy = yy + yd[dir];

	if (Check(nx, ny) == true && Check(nxx, nyy) == true)
		return;
	else if (Check(nx, ny) == true && Check(nxx, nyy) == false) {
		result = min(result, cnt);
		return;
	}
	else if (Check(nx, ny) == false && Check(nxx, nyy) == true) {
		result = min(result, cnt);
		return;
	}

	if (map[nx][ny] == '#') {
		nx = x;
		ny = y;
	}
	if (map[nxx][nyy] == '#') {
		nxx = xx;
		nyy = yy;
	}

	for (int i = 0;i < 4;i++)
		Move(nx, ny, nxx, nyy, cnt + 1, i);
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o')
				Coin.push_back({ i,j });
		}
	}
	for (int i = 0;i < 4;i++) {
		int x = Coin[0].first;
		int y = Coin[0].second;
		int xx = Coin[1].first;
		int yy = Coin[1].second;

		Move(x, y, xx, yy, 1, i);
	}

	if (result > 10)
		result = -1;
	cout << result << endl;
}