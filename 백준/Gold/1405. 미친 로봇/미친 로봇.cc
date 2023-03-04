#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

#define endl '\n'
#define MAX 15*2
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
double EWSN[4];
double result;
bool visit[MAX][MAX];

void dfs(int x, int y, double chance) {
	if (N == 0) {
		result += chance;
		return;
	}

	visit[x][y] = true;
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (!visit[nx][ny]) {
			N -= 1;
			dfs(nx, ny, chance * EWSN[i]);
			N += 1;
			visit[nx][ny] = false;
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < 4;i++) {
		cin >> EWSN[i];
		EWSN[i] *= 0.01;
	}

	dfs(15, 15, 1.0);

	cout << fixed;
	cout << setprecision(10) << result << endl;
}