#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
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

int N, M;
int cnt = 0;
int map[MAX][MAX];
queue<pair<int, int>> q;

void bfs() {	
	while (1) {
		int qsize = q.size();
		for (int i = 0;i < qsize;i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0;i < 8;i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny]>0) {
					map[nx][ny] -= 1;
					if (map[nx][ny] == 0) {
						q.push({ nx,ny });
					}
				}
			}
		}
		if (q.empty())
			break;
		cnt++;
	}
}

int main() {
	char c;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> c;
			if (c == '.') {
				q.push({ i,j });
				map[i][j] = 0;
			}
			else
				map[i][j] = c - '0';
		}
	}
	bfs();
	cout << cnt;
}