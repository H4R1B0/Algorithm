#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
vector<vector<int>> dist;
vector<vector<int>> Member;
bool visit[MAX];

void floyd() {
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void bfs(int Start) {
	queue<int> q;
	q.push(Start);
	vector<int> Group;
	Group.push_back(Start);
	visit[Start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1;i <= N;i++) {
			int next = dist[cur][i];
			if (!visit[i] && next != INF) {
				q.push(i);
				visit[i] = true;
				Group.push_back(i);
			}
		}
	}
	Member.push_back(Group);
}

int main() {
	cin >> N;
	cin >> M;
	dist.assign(N + 1,vector<int>(N+1,INF));
	for (int i = 1;i <= N;i++)
		dist[i][i] = 0;

	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = dist[b][a] = 1;
	}

	floyd();

	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (!visit[i]) {
			bfs(i);
			cnt++;
		}
	}

	vector<int> result;
	int cur, next;
	for (int k = 0;k < Member.size();k++) {
		pair<int, int> represent = { 0,INF };
		
		for (int i = 0;i < Member[k].size();i++) {
			int Max = 0;
			cur = Member[k][i];

			for (int j = 0;j < Member[k].size();j++) {
				next = Member[k][j];
				Max = max(dist[cur][next], Max);
			}
			if (Max < represent.second) {
				represent = { cur,Max };
			}
				
		}
		result.push_back(represent.first);
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;
}