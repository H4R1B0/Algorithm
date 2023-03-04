#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 102
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int T;
int map[MAX][MAX];
pair<int, int> point[MAX];

bool check(int a, int b) {
	if (abs(point[a].first - point[b].first) + abs(point[a].second - point[b].second) <= 1000)
		return true;
	return false;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0;i < N + 2;i++)
			cin >> point[i].first >> point[i].second;
		
		for (int i = 0;i < N + 2;i++)
			for (int j = 0;j < N + 2;j++)
				if (i != j)
					map[i][j] = MAX;

		for (int i = 0;i < N + 2;i++)
			for (int j = 0;j < N + 2;j++) {
				if (i == j)
					continue;
				if (check(i, j))
					map[i][j] = 1;
			}

		for (int k = 0; k < N + 2; k++) {
			for (int i = 0; i < N + 2; i++) {
				for (int j = 0; j < N + 2; j++) {
					if (map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}

		if (0 < map[0][N + 1] && map[0][N + 1] < MAX)
			cout << "happy"<<endl;
		else cout << "sad"<<endl;

	}
}