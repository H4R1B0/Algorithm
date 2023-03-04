#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 101+1
#define INF 987654321

int xd[4] = { -1, 0, 1, 0 };
int yd[4] = { 0, -1, 0, 1 };

int MAP[50][5];
int cal(int x, int y) {
	int n = max(abs(x), abs(y));
	int val = 2 * n + 1;
	val *= val;

	int diff = 2 * n;;
	if (x == n)
		return val - (n - y);
	val -= diff;
	if (y == -n)
		return val - (n - x);
	val -= diff;
	if (x == -n)
		return val - (y + n);
	val -= diff;
	return val - (x + n);
}

string getzero(int cnt) {
	string s = "";
	while (cnt--)
		s += " ";
	return s;
}

int main(void) {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int cnt = 0;
	for (int i = r1;i <= r2;i++) {
		for (int j = c1;j <= c2;j++) {
			cnt = max(cnt, (int)to_string(cal(i, j)).length());
		}
	}

	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j)\
			cout << getzero(cnt - (int)to_string(cal(i, j)).length()) << cal(i, j) << " ";
		putchar('\n');
	}
}