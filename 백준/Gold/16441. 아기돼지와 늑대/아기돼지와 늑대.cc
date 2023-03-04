#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 1e10
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K, S, P, Q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<vector<char>> MAP(N, vector<char>(M));
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	queue<pair<int, int>> q;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'W')
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (MAP[nx][ny] == '.' && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
				else {
					while (MAP[nx][ny] != '.') {
						if (MAP[nx][ny] == '#') {
							nx -= xd[i];
							ny -= yd[i];
							break;
						}
						nx += xd[i];
						ny += yd[i];
					}
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (MAP[i][j] == '.' && !visit[i][j])
				cout << 'P';
			else
				cout << MAP[i][j];
		}
		cout << endl;
	}
}