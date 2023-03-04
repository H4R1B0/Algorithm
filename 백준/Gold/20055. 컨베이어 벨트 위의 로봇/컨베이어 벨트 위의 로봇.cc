#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <deque>

using namespace std;
#define MAX 201
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, K;
deque<int> durability;
deque<bool> conveyor;

void rotate() {
	conveyor.push_front(conveyor.back());
	conveyor.pop_back();

	durability.push_front(durability.back());
	durability.pop_back();

	conveyor[N - 1] = false;
}

void move() {
	for (int i = N - 2;i >= 0;i--) {
		if (!conveyor[i + 1] && durability[i + 1] > 0 && conveyor[i]) {
			conveyor[i] = false;
			conveyor[i + 1] = true;
			durability[i + 1]--;
		}
	}
	conveyor[N - 1] = false;
}

int check() {
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (durability[i] == 0)
			cnt++;
	}
	return cnt;
}

int main(void) {
	cin >> N >> K;
	for (int i = 0;i < 2 * N;i++) {
		int a;
		cin >> a;
		durability.push_back(a);
		conveyor.push_back(false);
	}
	int answer = 1;
	while (true) {
		rotate();
		move();
		if (!conveyor[0] && durability[0] > 0) {
			conveyor[0] = true;
			durability[0]--;
		}
		if (check() >= K) {
			break;
		}			
		answer++;
	}
	cout << answer;
}