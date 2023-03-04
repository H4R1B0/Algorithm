#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 8+1

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };
int xd[] = { 0,0,1,-1,1,1,-1,-1,0 };
int yd[] = { 1,-1,0,0,1,-1,1,-1,0 };

string map[MAX];
bool visit[MAX][MAX][MAX];

int main() {
	for (int i = 0;i < 8;i++) {
		cin >> map[i];
	}
	queue<pair<pair<int, int>, int>> q;
	q.push({ {7,0},0 });
	visit[7][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();


		if (x == 0 && y == 7) {
			cout << 1;
			return 0;
		}

		for (int i = 0;i < 9;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			int nt = min(t + 1, 8);

			if (!(nx >= 0 && nx < 8 && ny >= 0 && ny < 8))
				continue;

			if (nx - t >= 0 && map[nx - t][ny] == '#')
				continue;

			if (nx - t - 1 >= 0 && map[nx - t - 1][ny] == '#')
				continue;

			if (!visit[nx][ny][nt]) {
				visit[nx][ny][nt] = true;
				q.push({ {nx,ny},nt });
			}
		}
	}
	cout << 0;
	return 0;
}