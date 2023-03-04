#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 20
#define endl '\n'

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };



struct SHARK {
	int x;
	int y;
	int dir;
	bool live;
	vector<int> priority[5];
};

struct MAP_INFO
{
	vector<int> v;
	int smell_time, smell_host;
};
int N, M, K;
MAP_INFO MAP[MAX][MAX];
SHARK shark[401];
int xd[] = { 0,-1,1,0,0 };
int yd[] = { 0,0,0,-1,1 };

bool check() {
	for (int i = 2;i <= M;i++) {
		if (shark[i].live == true)
			return false;
	}
	return true;
}

void setting_smell(int time) {
	for (int i = 1;i <= M;i++) {
		if (shark[i].live == false)
			continue;
		int x = shark[i].x;
		int y = shark[i].y;
		MAP[x][y].smell_time = time + K;
		MAP[x][y].smell_host = i;
	}
}

void move_shark(int time) {
	for (int i = 1;i <= M;i++) {
		if (shark[i].live == false)
			continue;
		int x = shark[i].x;
		int y = shark[i].y;
		MAP[x][y].v.clear();
	}

	for (int i = 1;i <= M;i++) {
		if (shark[i].live == false)
			continue;
		int x = shark[i].x;
		int y = shark[i].y;
		int dir = shark[i].dir;
		int self_x = -1, self_y = -1, self_dir = -1;
		bool flag = false;

		for (int j = 0;j < shark[i].priority[dir].size();j++) {
			int ndir = shark[i].priority[dir][j];
			int nx = x + xd[ndir];
			int ny = y + yd[ndir];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (MAP[nx][ny].smell_time <= time) {
					flag = true;
					MAP[nx][ny].v.push_back(i);
					shark[i].x = nx;
					shark[i].y = ny;
					shark[i].dir = ndir;
					break;
				}
				else if(MAP[nx][ny].smell_host==i) {
					if (self_x == -1) {
						self_x = nx;
						self_y = ny;
						self_dir = ndir;
					}
				}
			}
		}
		if (flag == false) {
			MAP[self_x][self_y].v.push_back(i);
			shark[i].x = self_x;
			shark[i].y = self_y;
			shark[i].dir = self_dir;
		}
	}
}

void kill_shark() {
	for (int i = 1;i <= M;i++) {
		if (shark[i].live == false)
			continue;
		int x = shark[i].x;
		int y = shark[i].y;
		if (MAP[x][y].v.size() >= 2) {
			sort(MAP[x][y].v.begin(), MAP[x][y].v.end());
			int live_num = MAP[x][y].v[0];
			for (int j = 1;j < MAP[x][y].v.size();j++) {
				int shark_num = MAP[x][y].v[j];
				shark[shark_num].live = false;
			}
			MAP[x][y].v.clear();
			MAP[x][y].v.push_back(live_num);
			MAP[x][y].smell_host = live_num;
		}
	}
}

int main(void) {
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int a;
			cin >> a;
			if (a != 0) {
				MAP[i][j].v.push_back(a);
				shark[a].x = i;
				shark[a].y = j;
			}
			MAP[i][j].smell_time = 0;
			MAP[i][j].smell_host = 0;
		}
	}
	for (int i = 1;i <= M;i++) {
		int dir;
		cin >> dir;
		shark[i].dir = dir;
		shark[i].live = true;
	}
	for (int i = 1;i <= M;i++) {
		for (int j = 1;j <= 4;j++) {
			int arr[4];
			cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
			for (int k = 0; k < 4; k++) {
				shark[i].priority[j].push_back(arr[k]);
			}
		}
	}

	for (int time = 0;time < 1001;time++) {
		if (check() == true) {
			cout << time;
			return 0;
		}
		setting_smell(time);
		move_shark(time);
		kill_shark();
	}
	cout << -1;
	return 0;
}