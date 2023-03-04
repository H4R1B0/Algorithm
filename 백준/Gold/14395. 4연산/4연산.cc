#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000000000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

long long N, M;
map<long long, int> visit;
void bfs() {
	queue<pair<int, string>> q;
	q.push({ N,"" });
	visit[N] = 1;

	while (!q.empty()) {
		long long cur = q.front().first;
		string str = q.front().second;
		q.pop();

		if (cur == M) {
			cout << str << endl;
			return;
		}
		long long next = 0;
		
		next = cur * cur;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			q.push({ next,str + '*' });
		}

		next = cur * 2;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			q.push({ next,str + '+' });
		}

		next = 0;
		if (next >= 0 && !visit[next]) {
			visit[next] = 1;
			q.push({ next,str + '-' });
		}
		
		if (cur != 0) {
			next = 1;
			if (next < MAX && !visit[next]) {
				visit[next] = 1;
				q.push({ next,str + '/' });
			}
		}		
	}
	cout << -1 << endl;
	return;
}

int main() {
	cin >> N >> M;
	if (N == M)
		cout << 0 << endl;
	else {
		bfs();
	}
}