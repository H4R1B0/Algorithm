#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
int map[MAX][MAX];
bool visit[MAX][MAX];

bool bfs(int min, int max) {
	if (map[1][1] < min || map[1][1] > max)
		return false;

	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	visit[1][1] = true;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
				if (!visit[nx][ny]) {
					if (map[nx][ny] <= max && map[nx][ny] >= min) {
						q.push(make_pair(nx, ny));
						visit[nx][ny] = true;
					}
				}
			}
		}
	}
	return visit[N][N];
}

bool go(int mid) {
	for (int i = 0; i + mid <= 200; i++) {
		if (bfs(i, i + mid))
			return true;
	}
	return false;
}

int main() {
	cin >> N;
	int Max = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> map[i][j];
			if (Max < map[i][j])
				Max = map[i][j];
		}
	}
	int right = Max;
	int left = 0;
	int result = Max;

	while (left <= right) {
		int mid = (left + right) / 2;
		memset(visit, false, sizeof(visit));
		if (go(mid)) {
			if (result > mid)
				result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << result;
}