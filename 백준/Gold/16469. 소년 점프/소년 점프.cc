#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int dist[101][101][3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dist, -1, sizeof(dist));
	cin >> N >> M;
	vector<vector<int>> MAP(N, vector<int>(M));
	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < M;j++) {
			MAP[i][j] = s[j] - '0';
		}
	}
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0;i < 3;i++) {
		int a, b;
		cin >> a >> b;
		q.push({ {a - 1,b - 1},i });
		dist[a - 1][b - 1][i] = 0;
	}
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (MAP[nx][ny] == 0 && dist[nx][ny][z] == -1) {
					dist[nx][ny][z] = dist[x][y][z] + 1;
					q.push({ {nx,ny},z });
				}
			}
		}
	}

	int cnt = 0;
	int Min = 10001;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int x = dist[i][j][0];
			int y = dist[i][j][1];
			int z = dist[i][j][2];
			int k = max(max(x, y), z);
			if (x != -1 && y != -1 && z != -1) {
				if (Min > k) {
					Min = k;
					cnt = 1;
				}
				else if(Min==k){
					cnt++;
				}
			}
		}
	}
	if (cnt)
		cout << Min << endl << cnt;
	else
		cout << -1;
}