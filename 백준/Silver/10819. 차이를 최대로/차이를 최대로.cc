#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 8+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int arr[MAX];
int use_arr[MAX];
bool visit[MAX];
int result;

int cal() {
	int sum = 0;
	for (int i = 0;i < N - 1;i++)
		sum += abs(use_arr[i] - use_arr[i + 1]);
	return sum;
}

void dfs(int cnt) {
	if (cnt == N) {
		result = max(result, cal());
	}

	for (int i = 0;i < N;i++) {
		if (visit[i])
			continue;

		use_arr[cnt] = arr[i];
		visit[i] = true;
		dfs(cnt + 1);
		visit[i] = false;
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i < N;i++) {
		visit[i] = true;
		use_arr[0] = arr[i];
		dfs(1);
		visit[i] = false;
	}
	cout << result;
}