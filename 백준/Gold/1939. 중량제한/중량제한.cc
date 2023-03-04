#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int Start, End;
vector<pair<int, int>> map[MAX];
bool visit[MAX];

bool bfs(int cost) {
	queue<int> q;
	q.push(Start);
	visit[Start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == End)
			return true;
		for(int i=0;i<map[cur].size();i++){
			int next = map[cur][i].first;
			int nextCost = map[cur][i].second;

			if (!visit[next] && cost <= nextCost) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main(void)
{
	cin >> N >> M;

	int maxCost = 0;
	for (int i = 0;i < M;i++) {
		int A, B, C;
		cin >> A >> B >> C;
		map[A].push_back({ B,C });
		map[B].push_back({ A,C });
		maxCost = max(maxCost, C);
	}

	cin >> Start >> End;

	int low = 0, high = maxCost;
	while(low <= high) {
		memset(visit, false, sizeof(visit));
		int mid = (low + high) / 2;

		if (bfs(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << high;
}