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

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int map[MAX][MAX];
bool visit[MAX][MAX][11];

int bfs() {
	//x,y,cnt,벽 뿌순 횟수,낮밤
	queue<pair<tuple<int,int,int>, pair<int, bool>>> q;
	q.push({ {1,1,1}, {0,true} });
	visit[1][1][0] = true;

	while (!q.empty()) {
		int x = get<0>(q.front().first);
		int y = get<1>(q.front().first);
		int cnt = get<2>(q.front().first);
		int k_cnt = q.front().second.first;
		bool daytime = q.front().second.second;
		q.pop();

		if (x == N && y == M) {
			return cnt;
		}
		
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (map[nx][ny] == 0) {
					if (!visit[nx][ny][k_cnt]) {
						visit[nx][ny][k_cnt] = true;
						q.push({ {nx,ny,cnt + 1}, {k_cnt,!daytime} });
					}					
				}
				else if (map[nx][ny] == 1) {
					if (k_cnt < K) {
						if (!visit[nx][ny][k_cnt + 1]) {
							if(daytime){
								visit[nx][ny][k_cnt + 1] = true;
								q.push({ {nx,ny,cnt + 1}, {k_cnt+1,!daytime} });
							}
							else {
								q.push({ {x,y,cnt + 1}, {k_cnt,!daytime} });
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < M;j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}

	cout << bfs();
}