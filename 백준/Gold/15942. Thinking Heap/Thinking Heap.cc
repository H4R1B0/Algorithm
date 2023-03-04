#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
int k, p;
int upCnt, downCnt;
int ans[MAX];

vector<int> up;
void getUp() {
	int tmp = p;
	while (tmp /= 2) {
		up.push_back(tmp);
	}
	reverse(up.begin(), up.end());
	if (up.size() >= k) {
		cout << -1;
		exit(0);
	}
	for (auto i : up)
		ans[i] = ++upCnt;
}

void dfs(int x) {
	ans[x] = downCnt--;
	if (x * 2 <= N)
		dfs(x * 2);
	if (x * 2 + 1 <= N)
		dfs(x * 2 + 1);
}
void getDown() {
	downCnt = N;
	if (2 * p <= N)
		dfs(2 * p);
	if (2 * p + 1 <= N)
		dfs(2 * p + 1);
	if (downCnt < k) {
		cout << -1;
		exit(0);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> k >> p;
	ans[p] = k;
	getUp();
	getDown();

	queue<int> q;
	for (int i = upCnt + 1;i <= downCnt;i++) {
		if (i == k)
			continue;
		q.push(i);
	}
	for (int i = 1;i <= N;i++) {
		if (ans[i])
			continue;
		ans[i] = q.front();
		q.pop();
	}
	for (int i = 1;i <= N;i++)
		cout << ans[i] << endl;
}