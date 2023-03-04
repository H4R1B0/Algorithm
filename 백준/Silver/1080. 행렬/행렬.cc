#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 51

int N, M;
bool arr[MAX][MAX];
bool result[MAX][MAX];
int cnt;

void flip(int x, int y) {
	cnt++;

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			arr[x + i][y + j] = !arr[x + i][y + j];
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0;j < M;j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0;j < M;j++) {
			result[i][j] = tmp[j] - '0';
		}
	}

	for (int i = 0;i < N - 2;i++) {
		for (int j = 0;j < M - 2;j++) {
			if (arr[i][j] != result[i][j])
				flip(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != result[i][j]) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	cout << cnt << endl;
}