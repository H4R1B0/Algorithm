#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"
#define MAX 100+1
#define INF 987654321
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K;
int map[MAX][10];
bool visit[MAX][10];

bool bfs(int a, int b) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ a,b });
	v.push_back({ a,b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < 10) {
				if (map[nx][ny] == map[x][y] && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					v.push_back({ nx,ny });
				}
			}
		}
	}

	if (v.size() >= K) {
		for (int i = 0;i < v.size();i++) {
			int x = v[i].first;
			int y = v[i].second;

			map[x][y] = 0;
		}
		return true;
	}
	return false;
}

void gravity() {
	for (int j = 0;j < 10;j++) {
		int k = N - 1;
		for (int i = N - 1;i >= 0;i--) {
			if (map[i][j] != 0)
				map[k--][j] = map[i][j];
		}
		for (int i = k;i >= 0;i--)
			map[i][j] = 0;
	}
}

bool work() {
	bool flag = false;
	memset(visit, false, sizeof(visit));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 10;j++) {
			if (map[i][j] != 0 && !visit[i][j]) {
				if (bfs(i, j))
					flag = true;
			}
		}
	}
	return flag;
}
void print_map() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 10;j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main(void) {
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 10;j++) {
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	while (work()) {
		gravity();
	}

	print_map();	
}
