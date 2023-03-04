#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int A, B, C, D;
map<pair<int, int>, int> visit;

int bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[{0, 0}] = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int cnt = visit[{a, b}];
		q.pop();

		if (a == C && b == D)
			return cnt;

		//F
		if (!visit.count({A,b})) {
			q.push({ A,b });
			visit[{A, b}] = cnt + 1;
		}
		if (!visit.count({ a,B })) {
			q.push({ a,B });
			visit[{a, B}] = cnt + 1;
		}
		//E
		if (!visit.count({ 0,b })) {
			q.push({ 0,b });
			visit[{0, b}] = cnt + 1;
		}
		if (!visit.count({ a,0 })) {
			q.push({ a,0 });
			visit[{a, 0}] = cnt + 1;
		}
		//M
		int newA, newB;
		if (a + b > B) {
			newA = a + b - B;
			newB = B;
		}
		else {
			newA = 0;
			newB = a + b;
		}
		if (visit.count({ newA, newB }) == 0) {
			q.push({ newA, newB });
			visit[{ newA, newB }] = cnt + 1;
		}
		if (a + b > A) {
			newA = A;
			newB = a + b - A;
		}
		else {
			newA = a + b;
			newB = 0;
		}
		if (visit.count({ newA, newB }) == 0) {
			q.push({ newA, newB });
			visit[{ newA, newB }] = cnt + 1;
		}
	}
	return -1;
}

int main() {
	cin >> A >> B >> C >> D;
	cout << bfs();
}