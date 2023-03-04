#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 1001
#define endl '\n'

int N;
int answer;
int Game[51][51];
bool Select[10];
int Order[10];

void Play() {
	int score = 0;
	int start_player = 1;
	int base_state[4];
	for (int i = 1;i <= N;i++) {
		int out_cnt = 0;
		bool next_inning = false;
		memset(base_state, 0, sizeof(base_state));
		while(1) {
			for (int j = start_player;j < 10;j++) {
				int player = Game[i][Order[j]];
				if (player == 0)
					out_cnt++;
				else if(player==1) {
					for (int F = 3;F >= 1;F--) {
						if (base_state[F] == 1) {
							if (F == 3) {
								base_state[F] = 0;
								score++;
							}
							else {
								base_state[F + 1] = 1;
								base_state[F] = 0;
							}
						}
					}
					base_state[1] = 1;
				}
				else if (player == 2) {
					for (int F = 3;F >= 1;F--) {
						if (base_state[F] == 1) {
							if (F == 3 || F==2) {
								base_state[F] = 0;
								score++;
							}
							else {
								base_state[F + 2] = 1;
								base_state[F] = 0;
							}
						}
					}
					base_state[2] = 1;
				}
				else if (player == 3) {
					for (int F = 3;F >= 1;F--) {
						if (base_state[F] == 1) {
							base_state[F] = 0;
							score++;
						}
					}
					base_state[3] = 1;
				}
				else {
					for (int F = 3;F >= 1;F--) {
						if (base_state[F] == 1) {
							base_state[F] = 0;
							score++;
						}
					}
					score++;
				}
				if (out_cnt == 3) {
					start_player = j + 1;
					if (start_player == 10)
						start_player = 1;
					next_inning = true;
					break;
				}
			}
			if (next_inning == true)
				break;
			start_player = 1;
		}
	}
	answer = max(answer, score);
}

void dfs(int cnt) {
	if (cnt == 10) {
		Play();
		return;
	}
	for (int i = 1;i <= 9;i++) {
		if (Select[i])
			continue;
		Select[i] = true;
		Order[i] = cnt;
		dfs(cnt + 1);
		Select[i] = false;
	}
}

int main(void) {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= 9;j++) {
			cin >> Game[i][j];
		}
	}
	Select[4] = true;
	Order[4] = 1;
	dfs(2);
	cout << answer;
}