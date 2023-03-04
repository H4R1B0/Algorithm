#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int cnt=1;
int MAP[MAX][MAX];
bool visit[MAX][MAX];
map<int, int> MAP_cnt;

void dfs(int x, int y) {
	visit[x][y] = true;
	MAP[x][y] = cnt;
	MAP_cnt[cnt]++;
	
	for (int i = 0;i < 4;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visit[nx][ny] && MAP[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin >> N>>M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (!visit[i][j] && MAP[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	int result = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (MAP[i][j] == 0) {
				set<int> s;
				for (int k = 0;k < 4;k++) {
					int nx = i + xd[k];
					int ny = j + yd[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (MAP[nx][ny] != 0) {
							s.insert(MAP[nx][ny]);
						}
					}
				}
				int ans = 1;
				for (auto i : s) {
					ans += MAP_cnt[i];
				}
				result = max(result, ans);
			}
		}
	}
	cout << result;
}