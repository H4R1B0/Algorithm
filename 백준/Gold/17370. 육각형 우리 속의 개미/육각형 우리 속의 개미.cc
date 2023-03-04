#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 30+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0, 1, 1, 0, -1, -1 };
int yd[] = { 2, 1, -1, -2, -1, 1 };


int N;
int cnt;
map<pair<int, int>, bool> visit;

void dfs(int x, int y, int dir, int move_cnt) {
	if (move_cnt == 0) {
		if (visit[{x, y}])
			cnt++;
		return;
	}
	else if (visit[{x, y}])
		return;

	visit[{x, y}] = true;

	int dir_right = (dir + 1) % 6;
	int dir_left = (dir + 5) % 6;
	dfs(x + xd[dir_right], y + yd[dir_right], dir_right, move_cnt - 1);
	dfs(x + xd[dir_left], y + yd[dir_left], dir_left, move_cnt - 1);

	visit[{x, y}] = false;
}

int main() {
	cin >> N;
	visit[{0, 0}] = true;
	dfs(0, 2, 0, N);
	cout << cnt;
}