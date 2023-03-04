#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int S, T;
bool visit[MAX];



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Tc;
	cin >> Tc;
	while (Tc--) {
		cin >> S >> T;
		memset(visit, false, sizeof(visit));
		queue<pair<pair<int, int>, int>> q;
		q.push({ {S,T},0 });
		visit[S] = true;
		while (!q.empty()) {
			int s = q.front().first.first;
			int t = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (s == t) {
				cout << cnt << endl;
				break;
			}
			if (s < t) {
				q.push({ {s * 2,t + 3},cnt + 1 });
				q.push({ {s + 1,t},cnt + 1 });
			}
			
		}
	}
}