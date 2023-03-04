#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 1100
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M;

int main(void) {
	int answer = 0;
	cin >> N >> M;
	vector<int> v(M);
	for (int i = 0;i < M;i++)
		cin >> v[i];
	for (int i = 1;i < M - 1;i++) {
		int left = 0, right = 0;
		for (int j = 0;j < i;j++)
			left = max(left, v[j]);
		for (int j = i + 1;j < M;j++)
			right = max(right, v[j]);
		answer += max(0, min(left, right) - v[i]);
	}
	cout << answer;
}