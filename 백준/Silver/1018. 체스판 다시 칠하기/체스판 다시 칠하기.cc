#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 51

int T;
int N, M;
char map[MAX][MAX];
string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string BW[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};

int BW_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (map[x + i][y + j] != BW[i][j])
				cnt++;
		}
	}
	return cnt;
}
int WB_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (map[x + i][y + j] != WB[i][j])
				cnt++;
		}
	}
	return cnt;
}


int main() {

	int result = 100;

	cin >> N >> M;
	

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0;i <= N-7;i++) {
		for (int j = 0;j <= M-7;j++) {
			int tmp = min(WB_cnt(i, j),BW_cnt(i, j));
			result = min(result, tmp);
		}
	}

	cout << result << endl;
}