#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 51
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int result = INF;
int empty_place;
int map[MAX][MAX];
int Time[MAX][MAX];
bool Select[11];
vector<pair<int, int>> virus;

void bfs(queue<pair<int, int>> q) {
	int infect_place = 0;
	int total_time = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (map[nx][ny] != 1 && Time[nx][ny] == -1) {
					Time[nx][ny] = Time[x][y] + 1;
					if (map[nx][ny] == 0) {
						infect_place++;
						total_time = Time[nx][ny];
					}
					q.push({ nx,ny });
				}
			}
		}
	}
	if (infect_place == empty_place)
		result = min(result, total_time);
	
}

void select_virus(int idx, int cnt) {
	if (cnt == M) {
		queue<pair<int, int>> q;
		memset(Time, -1, sizeof(Time));
		for (int i = 0;i < virus.size();i++) {
			if (Select[i] == true) {
				q.push({ virus[i].first,virus[i].second });
				Time[virus[i].first][virus[i].second] = 0;
			}
		}
		bfs(q);
		return;
	}

	for (int i = idx;i < virus.size();i++) {
		if (Select[i] == true)
			continue;
		Select[i] = true;
		select_virus(i + 1, cnt + 1);
		Select[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				empty_place++;
			else if (map[i][j] == 2)
				virus.push_back({ i,j });
		}

	select_virus(0, 0);

	if (result == INF)
		cout << -1 << endl;
	else
		cout << result << endl;
}