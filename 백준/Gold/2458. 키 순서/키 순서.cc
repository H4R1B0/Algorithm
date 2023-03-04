#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 501
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];

void floyd() {
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (map[i][k] && map[k][j])
					map[i][j] = 1;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	floyd();
	int result=0;
	for (int i = 1;i <= N;i++) {
		int cnt = 0;
		for (int j = 1;j <= N;j++) {
			if (i == j)
				continue;
			if (!map[i][j] && !map[j][i])
				cnt++;
		}
		if (!cnt)
			result++;
	}
	cout << result;
}