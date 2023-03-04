#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<int> visit;
vector<vector<int>> g;
vector<vector<int>> answer;
bool bfs(int x, vector<int> love) {
	queue<pair<int, vector<int>>> q;
	q.push({ x,love });

	while (!q.empty()) {
		int cur = q.front().first;
		vector<int> cur_love = q.front().second;
		q.pop();

		visit[cur] = x;

		for (int i = 0;i < love.size();i++) {
			int next = love[i];
			if (visit[next]==-1) {
				visit[next] = x;
				vector<int> tmp;
				for (int j = 0;j < N;j++) {
					if (g[next][j] == 0) {
						tmp.push_back(j);
					}
				}
				if (love != tmp)
					return false;
				q.push({ next,tmp });
			}
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	g.resize(N, vector<int>(N));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> g[i][j];
		}
	}
	visit.assign(N, -1);
	for (int i = 0;i < N;i++) {
		if (visit[i]==-1) {
			vector<int> love;
			for (int j = 0;j < N;j++) {
				if (g[i][j] == 0)
					love.push_back(j);
			}
			if (love.size() == 1) {
				cout << 0;
				return 0;
			}
			bool flag = bfs(i, love);
			if (flag == false) {
				cout << 0;
				return 0;
			}
			else {
				answer.push_back(love);
			}
		}
	}

	cout << answer.size() << endl;
	for (auto ans : answer) {
		for (auto i : ans) {
			cout << i+1 << " ";
		}
		cout << endl;
	}
}