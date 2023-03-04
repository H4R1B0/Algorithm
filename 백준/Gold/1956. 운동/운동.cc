#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 400+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int V, E;
int map[MAX][MAX];
bool visit[MAX];

void floyd() {
	for (int k = 1;k <= V;k++) {
		for (int i = 1;i <= V;i++) {
			for (int j = 1;j <= V;j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
}

int main(void)
{
	cin >> V >> E;

	for (int i = 1;i <= V;i++) {
		for (int j = 1;j <= V;j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 1;i <= E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}

	floyd();

	int result = INF;
	for (int i = 1;i <= V;i++) {
		result = min(result, map[i][i]);
	}

	if (result == INF)
		cout << -1;
	else
		cout << result;
}