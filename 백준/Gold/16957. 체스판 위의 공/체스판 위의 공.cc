#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321
#define ll long long

int xd[8] = { 0,0,1,-1,1,1,-1,-1 };
int yd[8] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int board[MAX][MAX];
int result[MAX][MAX];
priority_queue<pair<int, pair<int, int>>> pq;

void bfs() {
	while (!pq.empty()) {
		//int val = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		int Min = board[x][y];
		int ansx, ansy;
		bool flag = false;
		for (int i = 0;i < 8;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (Min > board[nx][ny]) {
					flag = true;
					Min = board[nx][ny];
					ansx = nx, ansy = ny;
				}
			}				
		}
		if (flag) {
			result[ansx][ansy] += result[x][y];
			result[x][y] = 0;
			//pq.push({ -board[ansx][ansy],{ansx,ansy} });
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> board[i][j];
			pq.push({ board[i][j],{i,j} });
			result[i][j] = 1;
		}
	}

	bfs();

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}