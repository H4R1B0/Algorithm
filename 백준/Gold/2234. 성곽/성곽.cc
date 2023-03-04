#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,-1,0,1 };
int yd[4] = { -1,0,1,0 };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> room;

bool check(int num1, int num2) {
	//cout << num << endl;
	if (num1 == num2)
		return true;
	return false;
}

void bfs(int a, int b) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int bit = 1;
		for (int i = 0;i < 4;i++) {
			if (!(map[x][y] & bit)) {
				int nx = x + xd[i];
				int ny = y + yd[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					cnt++;
				}
			}
			bit *= 2;
		}
	}
	room.push_back(cnt);
}

int main(void)
{
	//int num = 5;
	//bool aaa = num ^ 1 || num ^ 2 || num ^ 4 || num ^ 8;
	//cout << (5^4);
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!visit[i][j]) {
				bfs(i, j);
			}
		}
	}
	sort(room.begin(), room.end());
	cout << room.size() << endl << room[room.size() - 1] << endl;

	room.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int Wall = 1; Wall <= 8; Wall *= 2) {
				if ((map[i][j] & Wall) == Wall) {
					memset(visit, false, sizeof(visit));
					map[i][j] = map[i][j] - Wall;
					bfs(i, j);
					map[i][j] = map[i][j] + Wall;
				}
			}
		}
	}
	sort(room.begin(), room.end());
	cout << room[room.size() - 1] << endl;
}