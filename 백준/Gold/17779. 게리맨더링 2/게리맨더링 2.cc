#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 1000
#define endl '\n'

int N;
int answer = 1e9;
int MAP[21][21];
int Label[21][21];
pair<int, int> pos[4];

bool CanMakeLine(int x, int y, int d1, int d2) {
	if (x + d1 >= N || y - d1 < 0)
		return false;
	if (x + d2 >= N || y + d2 >= N)
		return false;
	if (x + d1 + d2 >= N || y - d1 + d2 >= N || y + d2 - d1 < 0)
		return false;
	return true;
}

void Cal() {
	int sum[6] = { 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			sum[Label[i][j]] = sum[Label[i][j]] + MAP[i][j];
		}
	}
	sort(sum, sum + 6);
	int Diff = sum[5] - sum[1];
	answer = min(answer, Diff);
}

void Labeling(int a, int b, int d1, int d2) {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			Label[i][j] = 5;
		}
	}

	int subArea = 0;
	for (int i = 0;i < pos[1].first;i++) {
		if (i >= pos[0].first)
			subArea++;
		for (int j = 0;j <= pos[0].second - subArea;j++) {
			Label[i][j] = 1;
		}
	}

	int plusArea = 0;
	for (int i = 0;i <= pos[2].first;i++) {
		if (i > pos[0].first)
			plusArea++;
		for (int j = pos[0].second + 1 + plusArea;j < N;j++) {
			Label[i][j] = 2;
		}
	}

	subArea = 0;
	for (int i = N - 1;i >= pos[1].first;i--) {
		if (i < pos[3].first)
			subArea++;
		for (int j = 0;j < pos[3].second - subArea;j++) {
			Label[i][j] = 3;
		}
	}

	plusArea = 0;
	for (int i = N - 1;i > pos[2].first;i--) {
		if (i <= pos[3].first)
			plusArea++;
		for (int j = pos[3].second + plusArea;j < N;j++) {
			Label[i][j] = 4;
		}
	}

	Cal();
}

int main(void) {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 1;j < N;j++) {
			for (int d1 = 1;d1 <= j;d1++) {
				for (int d2 = 1;d2 < N - j;d2++) {
					if (CanMakeLine(i, j, d1, d2) == true) {
						pos[0] = { i,j };
						pos[1] = { i + d1,j - d1 };
						pos[2] = { i + d2,j + d2 };
						pos[3] = { i + d1 + d2,j - d1 + d2 };
						Labeling(i, j, d1, d2);
					}
				}
			}
		}
	}

	cout << answer;
}