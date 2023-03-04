#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, T;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int bfs() {
	vector<bool> visit(N + 1, false);
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0}, {0,0} });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int idx = q.front().second.second;
		q.pop();

		if (y == T)
			return cnt;

		for (int i = idx;i < N;i++) {
			int nx = v[i].first;
			int ny = v[i].second;
			if (!visit[i]) {
				if (abs(x - nx) <= 2 && abs(y - ny) <= 2) {
					visit[i] = true;
					q.push({ {nx,ny}, {cnt + 1,i} });
				}
				else if (abs(x - nx) > 2 && abs(y - ny) > 2)
					break;
			}
		}
		for (int i = idx;i >= 0;i--) {
			int nx = v[i].first;
			int ny = v[i].second;
			if (!visit[i]) {
				if (abs(x - nx) <= 2 && abs(y - ny) <= 2) {
					visit[i] = true;
					q.push({ {nx,ny}, {cnt + 1,i} });
				}
				else if (abs(x - nx) > 2 && abs(y - ny) > 2)
					break;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> T;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(),cmp);
	
	cout << bfs();
}