#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, X;
vector<int> v[MAX];
bool visit[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	cin >> X;
	queue<int> q;
	q.push(X);
	visit[X] = true;
	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : v[cur]) {
			if (!visit[next]) {
				cnt++;
				visit[next] = true;
				q.push(next);
			}
		}
	}
	cout << cnt;
}