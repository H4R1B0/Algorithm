#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 51

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M,K;
int cnt;
int map[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int i, int j) {
	visit[i][j] = true;
	cnt++;

	for (int k = 0;k < 4;k++) {
		int newX = i + xd[k];
		int newY = j + yd[k];

		if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
			if (map[newX][newY] == 1 && !visit[newX][newY]) {
				dfs(newX, newY);
			}
		}
	}
}

int main(void)
{   
    int T;
    cin >> T;
	for (int i = 0 ;i < T;i++) {
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		vector<int> ans;

		cin >> M >> N >> K;

		for (int j = 0;j < K;j++) {
			int a, b;
			cin >> a >> b;
			map[b][a] = 1;
		}

		for (int j = 0;j < N;j++) {
			for (int k = 0;k < M;k++) {
				if (map[j][k] == 1 && !visit[j][k]) {
					cnt = 0;
					dfs(j, k);
					ans.push_back(cnt);
				}
			}
		}

		cout << ans.size()<<endl;
	}
}