#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 2000
#define endl '\n'

int xd[] = { -1,-1,-1,0 };
int yd[] = { -1,0,1,1 };

int N, W, L;

int main(void) {
	cin >> N >> W >> L;
	vector<int> arr(N);
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	queue<int> q;
	int sum = 0, answer = 0;
	for (int i = 0;i < N;i++) {
		while (1) {
			if (q.size() == W) {
				sum -= q.front();
				q.pop();
			}
			if (sum + arr[i] <= L)
				break;
			q.push(0);
			answer++;
		}
		q.push(arr[i]);
		sum += arr[i];
		answer++;
	}
	answer += W;
	cout << answer;
}