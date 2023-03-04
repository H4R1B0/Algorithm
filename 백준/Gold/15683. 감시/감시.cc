#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX (8+1)
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[] = { -1,0,1,0 };
int yd[] = { 0,1,0,-1 };

int N, M;
vector<int> angle;
vector<vector<int>> MAP;
vector<vector<int>> copy_MAP;
bool visit[MAX][MAX][4];
int answer = INF;
vector<pair<int, int>> cctvs;

void dfs(int cnt) {
	if (cnt == cctvs.size()) {
		for (int i = 0;i < angle.size();i++) {
			int x = cctvs[i].first;
			int y = cctvs[i].second;

			for (int j = 0;j < 4;j++) {
				if (visit[x][y][j]) {
					int nx = x + xd[(angle[i] + j) % 4];
					int ny = y + yd[(angle[i] + j) % 4];
					while (true) {
						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							break;
						if (MAP[nx][ny] == 6)
							break;						
						if (MAP[nx][ny] == 0)
							MAP[nx][ny] = 9;
						nx += xd[(angle[i] + j) % 4];
						ny += yd[(angle[i] + j) % 4];
					}
				}
			}
		}

		int tmp = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (MAP[i][j] == 0)
					tmp++;
			}
		}
		answer = min(answer, tmp);
		MAP = copy_MAP;
		return;
	}

	for (int i = 0;i < 4;i++) {
		angle.push_back(i);
		dfs(cnt + 1);
		angle.pop_back();
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	MAP.resize(N, vector<int>(M));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
			if (1 <= MAP[i][j] && MAP[i][j] <= 5) {
				cctvs.push_back({ i,j });
			}
			if (MAP[i][j] == 1) {
				visit[i][j][0] = true;
			}
			else if (MAP[i][j] == 2) {
				visit[i][j][0] = true;
				visit[i][j][2] = true;
			}
			else if (MAP[i][j] == 3) {
				visit[i][j][0] = true;
				visit[i][j][1] = true;
			}
			else if (MAP[i][j] == 4) {
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				visit[i][j][2] = true;
			}
			else if (MAP[i][j] == 5) {
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				visit[i][j][2] = true;
				visit[i][j][3] = true;
			}
		}
	}

	copy_MAP = MAP;
	dfs(0);
	cout << answer;
}