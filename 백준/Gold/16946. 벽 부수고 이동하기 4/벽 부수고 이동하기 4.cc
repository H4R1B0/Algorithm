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
#define MAX 1000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
int map[MAX][MAX];
int area_num[MAX][MAX];
int area_idx;
int result[MAX][MAX];
bool visit[MAX][MAX];

vector<int> area;

void bfs(int a, int b) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	area_num[a][b] = area_idx;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && map[nx][ny] == 0) {
					cnt++;
					area_num[nx][ny] = area_idx;
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	area.push_back(cnt);
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string str;cin >> str;
		for (int j = 0;j < str.length();j++) {
			map[i][j] = str[j] - '0';
		}
	}
	memset(area_num, -1, sizeof(area_num));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				bfs(i, j);
				area_idx++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				set<int> Search;
				for (int k = 0; k < 4; k++) {
					int nx = i + xd[k];
					int ny = j + yd[k];

					if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
						if (map[nx][ny] == 0) {
							if (Search.find(area_num[nx][ny]) == Search.end()) {
								Search.insert(area_num[nx][ny]);
								result[i][j] = result[i][j] + area[area_num[nx][ny]];
							}
						}
					}
				}
				result[i][j] = result[i][j] + 1;
				result[i][j] = result[i][j] % 10;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}
}