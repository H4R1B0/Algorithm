#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, Start, End;
int result = INF;
bool visit[MAX];
vector<int> v[MAX];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ Start,0 });
	visit[Start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == End) {
			result = min(result, cnt);
		}

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];

			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
	if (result == INF)
		return -1;
	return result;
}

int main() {
	cin >> Start >> End;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << bfs();
}