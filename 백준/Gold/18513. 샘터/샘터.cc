#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 4000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
queue<pair<int, int>> q;
set<int> s;

ll bfs() {
	ll ans = 0;
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			int cur = q.front().first;
			int p = q.front().second;
			q.pop();

			for (int i = 0;i < 2;i++) {
				int next = cur + yd[i];

				if (s.count(next) >= 1)
					continue;

				--K;
				ans += abs(next - p);

				if (K == 0) {
					return ans;
				}

				s.insert(next); 
				q.push({ next, p });
			}
		}
	}
	return ans;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> M;
		q.push({ M,M });
		s.insert(M);
	}

	cout << bfs();
}