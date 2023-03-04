#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int N, M;
int map[MAX][MAX];

void floyd() {
	for (int i = 1;i <= N;i++) {
		for (int a = 1;a <= N;a++) {
			for (int b = 1;b <= N;b++) {
				if (a == b)
					continue;

				else if (map[a][i] && map[i][b]) {
					if (map[a][b] == 0)
						map[a][b] = map[a][i] + map[i][b];
					else
						map[a][b] = min(map[a][b], map[a][i] + map[i][b]);

				}
			}
		}
	}
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	floyd();
	int result=INF;
	int person;

	for (int i = 1;i <= N;i++) {
		int sum = 0;

		for (int j = 1;j <= N;j++) {
			sum += map[i][j];
		}
		if (result > sum) {
			result = sum;
			person = i;
		}
	}

	cout << person;
}