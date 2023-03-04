#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int Team[MAX];
int map[MAX][MAX];
int Entry[MAX];

int main(void)
{
	int Tc;
	cin >> Tc;
	while (Tc--) {
		memset(map, 0, sizeof(map));
		memset(Entry, 0, sizeof(Entry));

		cin >> N;
		for (int i = 1;i <= N;i++) {
			cin >> Team[i];
		}
		for (int i = 1;i <= N;i++) {
			for (int j = i+1;j <= N;j++) {
				map[Team[i]][Team[j]] = 1;
				Entry[Team[j]]++;
			}
		}

		cin >> M;
		for (int i = 0;i < M;i++) {
			int a, b;
			cin >> a >> b;
			if (map[a][b]) {
				map[a][b] = 0;
				map[b][a] = 1;
				Entry[b]--;
				Entry[a]++;
			}
			else {
				map[b][a] = 0;
				map[a][b] = 1;
				Entry[a]--;
				Entry[b]++;
			}
		}

		queue<int> q;
		for (int i = 1;i <= N;i++) {
			if (!Entry[i])
				q.push(i);
		}

		bool result = true;
		vector<int> ans;
		while (!q.empty()) {
			if (q.size() > 1) {
				result = false;
				break;
			}
			
			int cur = q.front();
			q.pop();
			ans.push_back(cur);

			for (int next = 1;next <= N;next++) {
				if (map[cur][next]) {
					Entry[next]--;
					if (!Entry[next])
						q.push(next);
				}
			}
		}

		if (!result)
			cout << "?" << endl;
		else if (ans.size() == N) {
			for (int i = 0;i < ans.size();i++)
				cout << ans[i] << " ";
			cout << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}