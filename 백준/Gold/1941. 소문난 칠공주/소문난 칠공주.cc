#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 5+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int map[MAX][MAX];
bool Select[25];
int result;

bool checkFour() {
	int cnt = 0;
	for (int i = 0;i < 25;i++) {
		if (Select[i]) {
			int x = i / 5;
			int y = i % 5;

			if (map[x][y] == 2)
				cnt++;
		}
	}
	if (cnt >= 4)
		return true;
	return false;
}

bool bfs() {
	queue<pair<int, int>> q;
	bool check_select[MAX][MAX];
	bool queue_select[MAX][MAX];
	bool check_ans = false;

	memset(check_select, false, sizeof(check_select));
	memset(queue_select, false, sizeof(queue_select));

	int tmp = 0;
	for (int i = 0;i < 25;i++) {
		if (Select[i]) {
			int x = i / 5;
			int y = i % 5;
			check_select[x][y] = true;

			if (tmp == 0) {
				q.push({ x,y });
				queue_select[x][y] = true;
				tmp++;
			}
		}
	}

	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (cnt == 7) {
			return true;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
				if (check_select[nx][ny] && !queue_select[nx][ny]) {
					queue_select[nx][ny] = true;
					q.push({ nx,ny });
					cnt++;
				}
			}
		}
	}
	return false;
}

void dfs(int idx, int cnt) {
	if (cnt == 7) {
		if (checkFour()) {
			if (bfs()) {
				result++;
			}
		}
		return;
	}

	for (int i = idx;i < 25;i++) {
		if (Select[i])
			continue;
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

int main(void)
{
	for (int i = 0;i < 5;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < str.length();j++) {
			if (str[j] == 'Y')
				map[i][j] = 1;
			else
				map[i][j] = 2;
		}
	}
	dfs(0, 0);
	cout << result;
}