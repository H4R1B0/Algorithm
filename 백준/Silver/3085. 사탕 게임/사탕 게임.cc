#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 51

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N;
int answer;
string MAP[MAX];

void check() {
	int result = 1;
	for (int i = 0;i < N;i++) {
		int tmp = 1;
		for (int j = 1;j < N;j++) {
			if (MAP[i][j - 1] == MAP[i][j])
				tmp++;
			else {
				result = max(result, tmp);
				tmp = 1;
			}
		}
		result = max(result, tmp);
	}
	for (int i = 0;i < N;i++) {
		int tmp = 1;
		for (int j = 0;j < N-1;j++) {
			if (MAP[j+1][i] == MAP[j][i])
				tmp++;
			else {
				result = max(result, tmp);
				tmp = 1;
			}
		}
		result = max(result, tmp);
	}
	answer = max(answer, result);
}

int main(void) {
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> MAP[i];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N-1;j++) {
			swap(MAP[i][j], MAP[i][j + 1]);
			check();
			swap(MAP[i][j], MAP[i][j + 1]);

			swap(MAP[j][i], MAP[j + 1][i]);
			check();
			swap(MAP[j][i], MAP[j + 1][i]);
		}
	}
	cout << answer;
}