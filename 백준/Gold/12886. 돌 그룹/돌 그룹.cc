#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1500+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int A, B, C, Sum;
set<tuple<int, int, int>> Stone;
bool visit[MAX][MAX];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ A,B });
	visit[A][B] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int tmp[3] = { a,b,Sum - a - b };
		q.pop();

		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				if (tmp[i] < tmp[j]) {
					int num1 = tmp[i] * 2;
					int num2 = tmp[j] - tmp[i];
					if (!visit[num1][num2]) {
						visit[num1][num2] = true;
						q.push({ num1,num2 });
					}
				}
			}
		}
	}
	return visit[Sum / 3][Sum / 3];
}

int main() {
	cin >> A >> B >> C;
	Sum = A + B + C;
	if (Sum % 3 != 0) {
		cout << 0;
		return 0;
	}

	cout << bfs();
}