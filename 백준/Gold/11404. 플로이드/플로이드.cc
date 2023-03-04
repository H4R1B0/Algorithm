#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100001
#define INF 987654321

int N,M;
int map[101][101];


void floyd() {
	for (int i = 1;i <= N;i++) {
		for (int a = 1;a <= N;a++) {
			for (int b = 1;b <= N;b++) {
				if(map[a][i]!=INF && map[i][b]!=INF)
					map[a][b] = min(map[a][b], map[a][i] + map[i][b]);
			}
		}
	}
}

int main() {
	cin >> N>>M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0;i < M;i++) {
		int a, b,c;
		cin >> a >> b>>c;
		map[a][b] = min(map[a][b], c);
	}
	floyd();

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == j || map[i][j] == INF) {
				cout << "0 ";
			}
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
}