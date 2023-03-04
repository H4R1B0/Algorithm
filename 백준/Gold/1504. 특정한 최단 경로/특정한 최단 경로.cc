#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 801
#define INF 987654321

int N, E;
int map[MAX][MAX];

void floyd() {
	for (int i = 1;i <= N;i++) {
		for (int a = 1;a <= N;a++) {
			for (int b = 1;b <= N;b++) {
				map[a][b] = min(map[a][b], map[a][i] + map[i][b]);
			}
		}
	}
}


int main() {
	
	cin >> N >> E;
	for (int i = 0;i < E;i++) {
		int a, b,c;
		cin >> a >> b>>c;
		map[a][b] = map[b][a] = c;
	}
	int x, y;
	cin >> x >> y;
	
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == j)
				continue;
			if (map[i][j] == 0)
				map[i][j] = INF;
		}
	}

	floyd();
	if (map[1][x] == INF || map[x][y] == INF || map[y][N] == INF) {
		cout << "-1";
		return 0;
	}
	else {
		cout << min(map[1][x] + map[x][y] + map[y][N], map[1][y] + map[y][x] + map[x][N]);
	}
}