#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>

using namespace std;

#define endl '\n'
#define MAX 20+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,-1,1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K;
int MAP[MAX][MAX];
int Dice[7];
vector<int> cmd;

void rolldice(int dir) {
	int d1 = Dice[1];
	int d2 = Dice[2];
	int d3 = Dice[3];
	int d4 = Dice[4];
	int d5 = Dice[5];
	int d6 = Dice[6];
	if (dir == 0)
	{
		Dice[1] = d4;
		Dice[4] = d6;
		Dice[6] = d3;
		Dice[3] = d1;
	}
	else if (dir == 1)
	{
		Dice[4] = d1;
		Dice[6] = d4;
		Dice[3] = d6;
		Dice[1] = d3;
	}
	else if (dir == 2)
	{
		Dice[1] = d5;
		Dice[2] = d1;
		Dice[6] = d2;
		Dice[5] = d6;
	}
	else if (dir == 3)
	{
		Dice[5] = d1;
		Dice[1] = d2;
		Dice[2] = d6;
		Dice[6] = d5;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int sx, sy;
	cin >> N >> M >> sx >> sy >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0;i < K;i++) {
		int a;
		cin >> a;
		cmd.push_back(a-1);
	}

	int x = sx;
	int y = sy;
	for (int i = 0;i < cmd.size();i++) {
		int nx = x + xd[cmd[i]];
		int ny = y + yd[cmd[i]];
		int dir = cmd[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		rolldice(dir);
		if (MAP[nx][ny] == 0)
			MAP[nx][ny] = Dice[6];
		else {
			Dice[6] = MAP[nx][ny];
			MAP[nx][ny] = 0;
		}
		cout << Dice[1] << endl;
		x = nx;
		y = ny;
	}
}