#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 101+1
#define INF 987654321

int xd[4] = { -1, 0, 1, 0 };
int yd[4] = { 0, 1, 0, -1 };

struct ROBOT {
	int x, y, dir;
};

int A, B, N, M;
vector<ROBOT> Robots;
int MAP[101][101];

int getDir(char dir) {
	if (dir == 'N')
		return 0;
	if (dir == 'E')
		return 1;
	if (dir == 'S')
		return 2;
	if (dir == 'W')
		return 3;
}

int move(int num, char cmd, int cnt) {
	int ret = 0;
	int x = Robots[num].x;
	int y = Robots[num].y;
	int dir = Robots[num].dir;
	//cout << x << y << dir << endl;
	if (cmd == 'F') {
		int nx = x, ny = y;
		while (cnt--) {
			nx = nx + xd[dir];
			ny = ny + yd[dir];
			//cout << nx << " " << ny << endl;
			if (nx < 0 || nx >= B || ny < 0 || ny >= A)
				return -1;
			if (MAP[nx][ny] != 0)
				return MAP[nx][ny];
		}
		Robots[num].x = nx;
		Robots[num].y = ny;
		MAP[x][y] = 0;
		MAP[nx][ny] = num;
	}
	else if (cmd == 'R') {
		while (cnt--) {
			dir = (dir + 1) % 4;
		}
		Robots[num].dir = dir;
	}
	else if (cmd == 'L') {
		while (cnt--) {
			dir = (dir + 3) % 4;
		}
		Robots[num].dir = dir;
	}
	return ret;
}

int main(void) {
	Robots.push_back({ 0,0,0 });
	string answer = "";
	int error_cnt = 0;
	cin >> A >> B;
	cin >> N >> M;
	
	for (int i = 1;i <= N;i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;		
		Robots.push_back({ B - b,a - 1,getDir(c) });
		MAP[B - b][a - 1] = i;
	}
	for (int i = 1;i <= M;i++) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		if (error_cnt)
			continue;
		int tmp = move(a, c, b);
		if (tmp == -1) {
			answer = "Robot " + to_string(a) + " crashes into the wall";
			error_cnt++;
		}
		else if (tmp > 0) {
			answer = "Robot " + to_string(a) + " crashes into robot "+to_string(tmp);
			error_cnt++;
		}
	}
	if (error_cnt)
		cout << answer;
	else
		cout << "OK";
}