#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 301

int xd[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int yd[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int T, I;
bool visit[MAX][MAX];

int startX, endX, startY, endY;

void bfs(int x,int y) {

	queue<pair<pair<int, int>, int>> q;
	q.push({ { x,y },0 });
	visit[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (curX == endX && curY == endY) {
			cout << cnt << endl;
			return;
		}

		for (int i = 0;i < 8;i++) {
			int nextX = curX + xd[i];
			int nextY = curY + yd[i];

			if (nextX>=0 && nextX<I&&nextY>=0 && nextY<I) {
				if (!visit[nextX][nextY]) {
					visit[nextX][nextY] = true;
					q.push({ {nextX,nextY},cnt+1 });
				}
				
			}
		}
	}
}


int main() {
	cin >> T;
	for(int i = 0;i < T;i++) {
		memset(visit, false, sizeof(visit));

		cin >> I;
		
		cin >> startX >> startY;
		cin >> endX >> endY;
		
		bfs(startX, startY);
	}
	return 0;
}