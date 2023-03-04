#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
int result = INF;
int map[MAX][MAX];
bool visit[MAX][MAX];
bool Select[11];
vector<pair<int, int>> virus;
vector<pair<int, int>> select_virus;

bool check(){
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)		{
			if (map[i][j] == 1)
				continue;
			if (visit[i][j] == false)
				return false;
		}
	}
	return true;
}

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0;i < select_virus.size();i++){
		int x = select_virus[i].first;
		int y = select_virus[i].second;
		q.push({ x,y });
		visit[x][y] = true;
	}

	int cnt = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int k = 0;k < qsize;k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0;i < 4;i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (!visit[nx][ny] && map[nx][ny] != 1) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		if (q.size() != 0)
			cnt++;
	}
	if (check())
		result = min(result, cnt);
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		memset(visit, false, sizeof(visit));
		bfs();
		return;
	}

	for (int i = idx;i < virus.size();i++) {
		if (Select[i])
			continue;
		Select[i] = true;
		select_virus.push_back(virus[i]);
		dfs(i, cnt + 1);
		select_virus.pop_back();
		Select[i] = false;
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
	dfs(0, 0);

	if (result == INF)
		result = -1;
	cout << result << endl;
}