#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX (50+1)
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[] = { -1,0,1,0 };
int yd[] = { 0,1,0,-1 };

int R, C, T;
int MAP[MAX][MAX];
int tmp_MAP[MAX][MAX];
vector<pair<int, int>> robot;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> q;
	cin >> R >> C >> T;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1)
				robot.push_back({ i,j });
		}
	}

	while (T--) {
		memset(tmp_MAP, 0, sizeof(tmp_MAP));
		tmp_MAP[robot[0].first][robot[0].second] = -1;
		tmp_MAP[robot[1].first][robot[1].second] = -1;

		for (int i = 0;i < R;i++) {
			for (int j = 0;j < C;j++) {
				if (MAP[i][j] > 0)
					q.push({ i,j });
			}
		}
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			int num = MAP[x][y] / 5;
			int cnt = 0;
			for (int i = 0;i < 4;i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && MAP[nx][ny] != -1) {
					tmp_MAP[nx][ny] += num;
					cnt++;
				}
			}
			tmp_MAP[x][y] += MAP[x][y] - num * cnt;
		}
		for (int i = 0;i < R;i++) {
			for (int j = 0;j < C;j++) {
				MAP[i][j] = tmp_MAP[i][j];
			}
		}

		int x1= robot[0].first;
		MAP[x1][1] = 0;
		for (int i = 1;i <= C - 2;i++)
			MAP[x1][i + 1] = tmp_MAP[x1][i];
		for (int i = 1;i <= C-1;i++)
			MAP[0][i - 1] = tmp_MAP[0][i];
		for (int i = 1;i <= x1;i++)
			MAP[i-1][C-1] = tmp_MAP[i][C-1];
		for (int i = 0;i <= x1-2;i++)
			MAP[i + 1][0] = tmp_MAP[i][0];
		//MAP[x1 - 1][0] = 0;

		int x2 = robot[1].first;
		MAP[x2][1] = 0;
		for (int i = 1;i <= C - 2;i++)
			MAP[x2][i + 1] = tmp_MAP[x2][i];
		for (int i = 1;i <= C - 1;i++)
			MAP[R-1][i - 1] = tmp_MAP[R-1][i];
		for (int i = x2 + 2;i <= R - 1;i++)
			MAP[i - 1][0] = tmp_MAP[i][0];
		for (int i = x2;i <= R - 2;i++)
			MAP[i + 1][C - 1] = tmp_MAP[i][C - 1];
		//MAP[x2 + 1][0] = 0;
	}

	int answer = 0;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			//cout << MAP[i][j] << " ";
			answer += MAP[i][j];
		}
		//cout << endl;
	}
	cout << answer+2;
}