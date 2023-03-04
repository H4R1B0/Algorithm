#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 99999+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, T, G;
bool visit[MAX];

void bfs() {
	int result = -1;
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visit[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		//cout << cur << " " << cnt << endl;

		if (cur == G) {
			result = cnt;
			break;
		}			

		int next = cur + 1;
		if (next < MAX && !visit[next]) {
			q.push({ next,cnt + 1 });
			visit[next] = true;
		}

		if (cur * 2 < MAX) {
			string str = to_string(cur * 2);
			next = cur * 2 - (int)pow(10, str.length() - 1);
			if (next >= 0 && !visit[next]) {
				q.push({ next,cnt + 1 });
				visit[next] = true;
			}
		}
	}
	if (result != -1 && result <= T)
		cout << result << endl;
	else
		cout << "ANG" << endl;
}

int main() {
	cin >> N >> T >> G;
	bfs();
}