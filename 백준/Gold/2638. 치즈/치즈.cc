#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];
int visit[MAX][MAX];
vector<pair<pair<int, int>, bool>> v;
vector<pair<int, int>> Chz;
queue<pair<int, int>> nq;

void air() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void add_air() {
	while (!nq.empty()) {
		int x = nq.front().first;
		int y = nq.front().second;
		nq.pop();

		visit[x][y] = 1;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				nq.push({ nx,ny });
			}
		}
	}
}

void find_chz() {
	Chz.clear();
	for (int i = 0;i < v.size();i++) {
		if (v[i].second == true)
			continue;
		int x = v[i].first.first;
		int y = v[i].first.second;
		int cnt = 0;

		for (int j = 0;j < 4;j++) {
			int nx = x + xd[j];
			int ny = y + yd[j];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (!map[nx][ny] && visit[nx][ny]==1)
				cnt++;
		}
		if (cnt >= 2) {
			Chz.push_back({ x,y });
			v[i].second = true;
		}
	}
}

void melt() {
	for (int i = 0;i < Chz.size();i++) {
		int x = Chz[i].first;
		int y = Chz[i].second;

		map[x][y] = 0;
		nq.push({ x,y });
	}
}

bool check() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back({ {i,j},false });
				visit[i][j] = -1;
			}
		}
	}
	air();

	int Time = 0;
	while (1) {
		if (check())
			break;
		find_chz();
		melt();
		add_air();
		Time++;
	}
	cout << Time;
}