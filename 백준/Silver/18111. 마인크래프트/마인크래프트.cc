#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 501

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M, B;
int MAP[MAX][MAX];

int main(void) {
	cin >> N >> M >> B;
	int answer[2] = { 987654321,0 };
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	for (int h = 0;h <= 256;h++) {
		int build = 0;
		int remove = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				int height = MAP[i][j] - h;
				if (height > 0)
					remove += height;
				else
					build -= height;
			}
		}
		if (remove + B >= build) {
			int time = remove * 2 + build;
			if (answer[0] >= time) {
				answer[0] = time;
				answer[1] = h;
			}
		}
	}
	cout << answer[0] << " " << answer[1];
}