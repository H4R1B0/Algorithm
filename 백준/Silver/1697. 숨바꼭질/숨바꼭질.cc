#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100001

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, K;
int result;
bool visit[MAX];
queue<pair<int, int>> q;
bool valid(int n) {
	if (n < 0 || n > 100000 || visit[n])
		return false;
	return true;
}

void bfs(int start) {
	while (!q.empty()) {
		int data = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (data == K) {
			result = cnt;
			break;
		}

		if (valid(data-1)) {
			visit[data - 1] = true;
			q.push({ data - 1, cnt + 1 });
		}
		if (valid(data + 1)) {
			visit[data + 1] = true;
			q.push({ data + 1, cnt + 1 });
		}
		if (valid(data *2)) {
			visit[data * 2] = true;
			q.push({ data * 2, cnt + 1 });
		}
	}
}
int main(void)
{
	cin >> N >> K;
	q.push({ N,0 });
	visit[N] = true;
	bfs(N);
	cout << result;
}