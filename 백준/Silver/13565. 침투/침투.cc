#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<pair<int,int>> v;

string bfs() {
	queue<pair<int, int>> q;
	for (int i = 0;i < v.size();i++) {
		q.push(v[i]);
		visit[v[i].first][v[i].second] = true;
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == N - 1) {
			return "YES";
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && map[nx][ny] == 0) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	return "NO";
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string str;cin >> str;
		for (int j = 0;j < M;j++) {
			map[i][j] = str[j] - '0';
			if (i == 0 && map[i][j] == 0)
				v.push_back({ i,j });
		}
	}
	cout << bfs();
}