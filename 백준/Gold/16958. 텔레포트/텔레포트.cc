#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


struct INFO {
	int s, x, y;
};
int N, T, M;
INFO arr[MAX];
int map[MAX][MAX];

int move_dist(int a, int b) {
	int dist = abs(arr[a].x - arr[b].x) + abs(arr[a].y - arr[b].y);
	if (arr[a].s && arr[b].s) {		
		return min(dist, T);
	}
	return dist;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i].s >> arr[i].x >> arr[i].y;
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == j)
				continue;
			map[i][j] = move_dist(i, j);
		}
	}

	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	cin >> M;
	while (M--) {
		int A, B;
		cin >> A >> B;
		cout << map[A][B] << endl;
	}
}