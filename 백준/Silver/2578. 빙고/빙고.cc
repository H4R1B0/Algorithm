#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 501
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M, B;
int MAP[5][5];
bool check[5][5];
void cal(int num) {
	bool flag = false;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (MAP[i][j] == num) {
				check[i][j] = true;
				flag = true;
				break;
			}				
		}
		if (flag)
			break;
	}
}

bool bingo() {
	int cnt = 0;
	for (int i = 0;i < 5;i++) {
		if (check[i][0] && check[i][1] && check[i][2] && check[i][3] && check[i][4])
			cnt++;
	}
	for (int i = 0;i < 5;i++) {
		if (check[0][i] && check[1][i] && check[2][i] && check[3][i] && check[4][i])
			cnt++;
	}
	if (check[0][0] && check[1][1] && check[2][2] && check[3][3] && check[4][4])
		cnt++;
	if (check[0][4] && check[1][3] && check[2][2] && check[3][1] && check[4][0])
		cnt++;
	if (cnt >= 3)
		return true;
	return false;
}

int main(void) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> MAP[i][j];
		}
	}
	int a;
	int answer = -1;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> a;
			cal(a);
			if (answer == -1 && bingo()) {
				answer = i * 5 + j+1;
			}
		}
	}
	cout << answer;
}