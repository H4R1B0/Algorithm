#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 55
#define endl '\n'

int xd[] = { -1,-1,0,1,1,1,0,-1 };
int yd[] = { 0,1,1,1,0,-1,-1,-1 };

int N;
int arr[50001];

bool check() {
	int prev = min(arr[0], N + 1 - arr[0]);
	for (int i = 1;i < N;i++) {
		int Min = min(arr[i], N + 1 - arr[i]);
		int Max = max(arr[i], N + 1 - arr[i]);
		if (prev <= Min)
			prev = Min;
		else if (Min < prev && prev <= Max)
			prev = Max;
		else
			return false;
	}
	return true;
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0;i < N;i++) {
			cin >> arr[i];
		}
		if (check())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}