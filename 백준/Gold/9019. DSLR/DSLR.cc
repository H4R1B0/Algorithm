#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };


int D, S, L, R;
int A, B;
bool visit[MAX];

void bfs(int start) {
	queue<pair<int, string>> q;
	q.push({ start,"" });
	visit[start] = true;

	while (!q.empty()) {
		int cur_num = q.front().first;
		string cur_str = q.front().second;
		q.pop();

		if (cur_num == B) {
			cout << cur_str << endl;
			break;
		}

		int D, S, L, R, tmp;
		D = (cur_num * 2) % 10000;
		if (!visit[D]) {
			visit[D] = true;
			q.push({ D,cur_str + "D" });
		}

		S = cur_num - 1 < 0 ? 9999 : cur_num - 1;
		if (!visit[S]) {
			visit[S] = true;
			q.push({ S,cur_str + "S" });
		}

		L = (cur_num % 1000) * 10 + (cur_num / 1000);
		if (!visit[L]) {
			visit[L] = true;
			q.push({ L,cur_str + "L" });
		}

		R = cur_num / 10 + (cur_num % 10) * 1000;
		if (!visit[R]) {
			visit[R] = true;
			q.push({ R,cur_str + "R" });
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(visit, false, sizeof(visit));
		cin >> A >> B;

		bfs(A);
	}
}