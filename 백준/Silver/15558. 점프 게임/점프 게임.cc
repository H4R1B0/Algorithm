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
#define MAX 100000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K;
int map[2][MAX];
bool visit[2][MAX];

void  bfs() {
	bool flag = false;
	//현재 줄, 위치
	queue<pair<pair<int,int>,int>> q;
	q.push({ {0,0},0 });
	visit[0][0] = true;

	while (!q.empty() && flag == false) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int Time = q.front().second;
		q.pop();
		
		if (Time >= N)
			break;

		for (int i = 0;i < 2;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (ny >= N)
				flag = true;
			if (nx >= 0 && nx<2 && ny>Time && ny < N) {
				if (map[nx][ny] == 1 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx,ny},Time + 1 });
				}
			}
		}
		for (int i = 2;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i]+K;

			if (ny >= N)
				flag = true;
			if (nx >= 0 && nx<2 && ny>Time && ny < N) {
				if (map[nx][ny] == 1 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx,ny},Time + 1 });
				}
			}
		}
	}

	if (flag)
		cout << 1;
	else
		cout << 0;
}

int main() {
	cin >> N >> K;
	for (int i = 0;i < 2;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < str.length();j++)
			map[i][j] = str[j] - '0';
	}
	bfs();
}