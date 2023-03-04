#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
bool Select[MAX];
bool visit[MAX];
vector<int> v[MAX];

void bfs(int x) {
	queue<pair<int, bool>> q;
	q.push({ x,true });
	visit[x] = true;
	Select[x] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		bool state = q.front().second;
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				Select[next] = !state;
				q.push({ next,!state });
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int M;
		cin >> M;
		for (int j = 0;j < M;j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	for (int i = 1;i <= N;i++) {
		if (!visit[i]) {
			bfs(i);
		}
	}

	vector<int> ans1, ans2;
	for (int i = 1;i <= N;i++) {
		if (Select[i] == true)
			ans1.push_back(i);
		else
			ans2.push_back(i);
	}

	cout << ans1.size() << endl;
	for (int i = 0;i < ans1.size();i++) {
		cout << ans1[i] << " ";
	}
	cout << endl;
	cout << ans2.size() << endl;
	for (int i = 0;i < ans2.size();i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;

}