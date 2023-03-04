#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 3000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int camp[MAX][3];
bool visit[MAX];
vector<vector<int>> map;

void dfs(int x) {
	visit[x] = true;

	for (int i = 0;i < map[x].size();i++) {
		if (!visit[map[x][i]])
			dfs(map[x][i]);
	}
}

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0;t < T;t++) {
		map.clear();
		memset(visit, false, sizeof(visit));

		cin >> N;
		map.resize(N);

		for (int i = 0;i < N;i++)
			cin >> camp[i][0] >> camp[i][1] >> camp[i][2];

		for (int i = 0;i < N;i++) {
			for (int j = i + 1;j < N;j++) {
				int x = camp[i][0] - camp[j][0];
				int y = camp[i][1] - camp[j][1];
				double r = (double)camp[i][2] + (double)camp[j][2];
				double d = sqrt(x * x + y * y);

				if (d <= r) {
					map[i].push_back(j);
					map[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0;i < N;i++) {
			if (!visit[i]) {
				cnt++;
				for (int j = 0;j < map[i].size();j++) {
					dfs(map[i][j]);
				}
			}
			
		}
		cout << cnt << endl;
	}
}