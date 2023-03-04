#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, K;
int S, X, Y;
int map[MAX][MAX];
vector<pair<int, pair<int, int>>> virus;

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0;i < virus.size();i++) {
		q.push({ virus[i].second.first,virus[i].second.second });
	}
	for (int s = 0;s < S;s++) {
		int qsize = q.size();
		for (int i = 0;i < qsize;i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0;k < 4;k++) {
				int nx = x + xd[k];
				int ny = y + yd[k];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[x][y];
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}


int main(void)
{
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] != 0)
				virus.push_back({ map[i][j],{i,j} });
		}
	}
	cin >> S >> X >> Y;
	sort(virus.begin(), virus.end());
	bfs();
	cout << map[X - 1][Y - 1];
}