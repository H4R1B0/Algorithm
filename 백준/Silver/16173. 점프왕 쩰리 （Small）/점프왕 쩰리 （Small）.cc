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
#define MAX 3+1
#define INF 987654321
//#define INF 10000000000
#define ll long long

int xd[] = { 0,1 };
int yd[] = { 1,0 };

//int xd[] = { 0,0,1,-1,1,1,-1,-1 };
//int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int map[MAX][MAX];
bool visit[MAX][MAX];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == N - 1 && y == N - 1) {
			cout << "HaruHaru" << endl;
			return;
		}

		int dist = map[x][y];
		for (int i = 0;i < 2;i++) {			
			int nx = x + xd[i] * dist;
			int ny = y + yd[i] * dist;

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

	cout << "Hing" << endl;
	return;
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}
	bfs();
}