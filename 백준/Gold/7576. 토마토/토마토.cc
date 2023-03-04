#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int N, M;
int map[1001][1001];
int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };
int total = 0, days = 0;;
int bfs() {
	while (!q.empty()) {
		int qsize = q.size();
		total += qsize;
		if (total == N * M) {
			return days;
		}
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int next_x = x + xd[k];
				int next_y = y + yd[k];
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && map[next_x][next_y] == 0) {
					map[next_x][next_y] = 1;
					q.push({ next_x, next_y });
				}
			}
		}
		days++;
	}
	if (total != N * M)
		return -1;
	return days;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({ i,j });
			else if (map[i][j] == -1)
				total++;
		}
	}
	cout << bfs() << endl;
	return 0;
}