#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 201
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M;
int parent[7];
int MAP[11][11];
bool visit[11][11];
bool islandVisit[7];
vector<pair<int, pair<int, int>>> v;

void CheckNum(int a, int b, int idx) {
	visit[a][b] = true;
	queue<pair<int, int>> q;
	q.push({ a,b });
	MAP[a][b] = idx;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && MAP[nx][ny]) {
					visit[nx][ny] = true;
					MAP[nx][ny] = idx;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void MakeBridge(int num, int a, int b) {
	for (int i = 0;i < 4;i++) {
		int x = a;
		int y = b;
		int dist = 0;
		while (true) {
			x += xd[i];
			y += yd[i];
			if (x < 0 || x >= N || y < 0 || y >= M)
				break;
			if (MAP[x][y]) {
				v.push_back({ dist,{num,MAP[x][y]} });
				//cout << dist << num << MAP[x][y] << endl;
				break;
			}
			if (MAP[x][y] == num)
				continue;
			dist++;
		}
	}
}

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

int main(void) {
	cin >> N >> M;
	for (int i = 1;i <= 6;i++)
		parent[i] = i;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	
	int cnt = 1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!visit[i][j] && MAP[i][j]) {
				CheckNum(i, j, cnt);
				cnt++;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (MAP[i][j])
				MakeBridge(MAP[i][j], i, j);
		}
	}

	int answer = 0;
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++) {
		int dist = v[i].first;
		int island1 = v[i].second.first;
		int island2 = v[i].second.second;
		//cout << dist << island1 << island2 << endl;

		if (dist < 2)
			continue;

		if (Find(island1) != Find(island2)) {
			//cout << dist << island1 << island2 << endl;
			Union(island1, island2);
			answer += dist;
		}
	}
	//cout << answer << endl;
	int tmp = 0;
	for (int i = 1;i < cnt;i++) {
		//cout << parent[i]<<" ";
		if (parent[i] == i)
			tmp++;
	}
	if (tmp == 1)
		cout << answer;
	else
		cout << -1;
}