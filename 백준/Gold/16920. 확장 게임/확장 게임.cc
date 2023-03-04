#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, P;
char map[MAX][MAX];
int player_move[10];
queue<pair<int, int>> q[10];
int player_cnt[10];

void bfs() {

	while (1) {
		bool flag = true;
		for (int i = 1;i <= P;i++) {
			if (!q[i].empty()) {
				flag = flag & false;
			}
		}
		if (flag == true)
			return;

		for (int p = 1;p <= P;p++) {
			
			int dist = player_move[p];
			while (!q[p].empty() && dist--) {
				int qsize = q[p].size();
				for (int i = 0;i < qsize;i++) {
					int x = q[p].front().first;
					int y = q[p].front().second;
					q[p].pop();

					for (int k = 0;k < 4;k++) {
						int nx = x + xd[k];
						int ny = y + yd[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '.') {
							map[nx][ny] = '0' + p;
							q[p].push({ nx,ny });
							player_cnt[p]++;
						}
					}
				}
			}
			
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> P;
	for (int i = 1;i <= P;i++) {
		cin >> player_move[i];
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] >= '1' && map[i][j] <= '9') {
				q[map[i][j] - '0'].push({ i,j });
				player_cnt[map[i][j] - '0']++;
			}
		}
	}
	bfs();

	for (int i = 1;i <= P;i++) {
		cout << player_cnt[i] << " ";
	}
}