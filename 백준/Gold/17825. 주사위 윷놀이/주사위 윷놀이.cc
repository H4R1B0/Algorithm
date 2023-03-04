#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 10
#define endl '\n'

int xd[] = { 0,1,0,-1 };
int yd[] = { -1,0,1,0 };

int N;
int arr[10];
int mal[4];
int MAP[35];
int turn[35];
bool check[35];
int score[35];
int answer;

void dfs(int cnt, int sum) {
	if (cnt == 10) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0;i < 4;i++) {
		int prev = mal[i];
		int now = prev;
		int move = arr[cnt];
		if (turn[now] > 0) {
			now = turn[now];
			move -= 1;
		}
		while (move--) {
			now = MAP[now];
		}
		if (now != 21 && check[now] == true)
			continue;
		check[prev] = false;
		check[now] = true;
		mal[i] = now;
		dfs(cnt + 1, sum + score[now]);
		mal[i] = prev;
		check[prev] = true;
		check[now] = false;
	}
}

int main(void) {
	for (int i = 0;i < 10;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i < 30;i++)
		MAP[i] = i + 1;
	MAP[21] = 21;
	MAP[30] = 25;MAP[31] = 32;MAP[32] = 25;MAP[27] = 20;
	turn[5] = 22;turn[10] = 31;turn[15] = 28;turn[25] = 26;
	
	for (int i = 0;i < 21;i++)
		score[i] = i * 2;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[31] = 22; score[32] = 24; score[28] = 28;
	score[29] = 27; score[30] = 26; score[25] = 25;
	score[26] = 30; score[27] = 35;

	dfs(0, 0);

	cout << answer;
}