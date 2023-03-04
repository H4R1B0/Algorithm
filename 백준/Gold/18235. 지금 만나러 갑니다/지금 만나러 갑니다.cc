#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };
int d[] = { 1, -1 };
int N, A, B;
vector<vector<int>> visitA;
vector<vector<int>> visitB;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> A >> B;
	visitA.resize(20, vector<int>(N + 1,-1));
	visitB.resize(20, vector<int>(N + 1,-1));

	queue<pair<int, int>> q;
	q.push({ A,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		int dist = 1 << cnt;
		q.pop();

		for (int i = 0;i < 2;i++) {
			int next = cur + d[i] * dist;
			if (next >= 1 && next <= N) {
				if (visitA[cnt + 1][next] == -1) {
					visitA[cnt + 1][next] = cnt + 1;
					q.push({ next,cnt + 1 });
				}
			}
		}
	}
	while (!q.empty())
		q.pop();

	q.push({ B,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		int dist = 1 << cnt;
		q.pop();

		if (visitA[cnt][cur] != -1 && visitA[cnt][cur] == visitB[cnt][cur]) {
			cout << cnt;
			return 0;
		}

		for (int i = 0;i < 2;i++) {
			int next = cur + d[i] * dist;
			if (next >= 1 && next <= N) {
				if (visitB[cnt + 1][next] == -1) {
					visitB[cnt + 1][next] = cnt + 1;
					q.push({ next,cnt + 1 });
				}
			}
		}
	}
	cout << -1;
}