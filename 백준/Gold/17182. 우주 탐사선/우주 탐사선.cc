#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 10+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K, result = INF;
int map[MAX][MAX];
bool visit[MAX];

void floyd() {
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
}

void dfs(int start, int dist, int cnt) {
	if (result < dist)
		return;
	if (cnt == N) {
		result = min(result, dist);
		return;
	}

	for (int i = 0;i < N;i++) {
		if (visit[i])
			continue;
		visit[i] = true;
		dfs(i, dist + map[start][i], cnt + 1);
		visit[i] = false;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}
	floyd();
	visit[K] = true;
	dfs(K, 0, 1);
	cout << result;
}