#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 300000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K, X;
vector<int> map[MAX];
bool visit[MAX];
vector<int> result;

void bfs() {
	queue<pair<int,int>> q;
	q.push({ X,0 });
	visit[X] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt == K) {
			result.push_back(cur);
		}

		for (int i = 0;i < map[cur].size();i++) {
			int next = map[cur][i];

			if (!visit[next]) {
				q.push({ next,cnt + 1 });
				visit[next] = true;
			}
		}
	}

	if (result.size() == 0) {
		cout << -1 << endl;
		return;
	}
	else {
		sort(result.begin(), result.end());
		for (int i = 0;i < result.size();i++)
			cout << result[i] << endl;
	}
}

int main(void)
{
	cin >> N >> M >> K >> X;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
	}
	bfs();
}