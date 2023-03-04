#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 101+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
char map[MAX][MAX];
int door[3][MAX][MAX];
vector<pair<int, int>> prisoner;

void dijkstra(int idx, int a, int b) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{a,b} });
	door[idx][a][b] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (door[idx][x][y] < cost)
			continue;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx <= N + 1 && ny >= 0 && ny <= M + 1) {
				char next = map[nx][ny];
				int ncost = cost;

				if (next == '*')
					continue;
				else if (next == '#')
					ncost++;

				if (door[idx][nx][ny] > ncost) {
					door[idx][nx][ny] = ncost;
					pq.push({ -ncost,{nx,ny} });					
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		prisoner.clear();
		cin >> N >> M;
		for (int i = 0;i <= N + 1;i++) {
			for (int j = 0;j <= M + 1;j++) {
				if (i == 0 || i == N + 1 || j == 0 || j == M + 1) {
					map[i][j] = '.';
				}
				else {
					cin >> map[i][j];
					if (map[i][j] == '$') {
						prisoner.push_back({ i,j });
					}
				}
			}
		}

		memset(door, 0xf, sizeof(door));
		dijkstra(0, 0, 0);
		dijkstra(1, prisoner[0].first, prisoner[0].second);
		dijkstra(2, prisoner[1].first, prisoner[1].second);

		int result = INF;
		int open_doors;
		for (int i = 0;i <= N + 1;i++) {
			for (int j = 0;j <= M + 1;j++) {
				if (map[i][j] == '*')
					continue;

				open_doors = door[0][i][j] + door[1][i][j] + door[2][i][j];
				if (map[i][j] == '#')
					open_doors -= 2;
				result = min(result, open_doors);
			}
		}
		cout << result << endl;
	}	
}