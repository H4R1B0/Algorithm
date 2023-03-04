#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 11
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, result = INF;
int map[MAX];
bool connect[MAX][MAX];
bool sel[MAX];
bool visit[MAX];

void calculate() {
	int A_cnt = 0, B_cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (sel[i] == true)
			A_cnt += map[i];
		else
			B_cnt += map[i];
	}
	result = min(result, abs(A_cnt - B_cnt));
}

bool check_connect(vector<int> v, bool T) {
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(v[0]);
	visit[v[0]] = true;
	int cnt = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1;i <= N;i++) {
			if (connect[cur][i] == true && sel[i] == T && !visit[i]) {
				visit[i] = true;
				cnt++;
				q.push(i);
			}
		}
	}

	if (v.size() == cnt)
		return true;
	return false;
}

bool check() {
	vector<int> A, B;
	for (int i = 1;i <= N;i++) {
		if (sel[i])
			A.push_back(i);
		else
			B.push_back(i);
	}

	if (!A.size() || !B.size())
		return false;

	bool Astate = check_connect(A, true);
	if (Astate == false)
		return Astate;

	bool Bstate = check_connect(B, false);
	if (Bstate == false)
		return Bstate;

	return true;
}

void dfs(int idx, int cnt) {
	if (cnt >= 1) {
		if (check()) {
			calculate();
		}
	}

	for (int i = idx;i <= N;i++) {
		if (sel[i])
			continue;
		sel[i] = true;
		dfs(i, cnt + 1);
		sel[i] = false;
	}
}

int main(void)
{
	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> map[i];
	for (int i = 1;i <= N;i++) {
		int a;
		cin >> a;
		for (int j = 0;j < a;j++) {
			int b;
			cin >> b;
			connect[i][b] = true;
			connect[b][i] = true;
		}
	}

	dfs(1, 0);
	
	if (result == INF)
		cout << -1 << endl;
	else
		cout << result << endl;
}