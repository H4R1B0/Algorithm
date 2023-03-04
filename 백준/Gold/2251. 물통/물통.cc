#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 201
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int A, B, C;
bool visit[MAX][MAX][MAX];
vector<int> result;

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},C });
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visit[a][b][c])
			continue;

		visit[a][b][c] = true;
		if (a == 0)
			result.push_back(c);

		if (a + b > B)
			q.push({ {a + b - B,B},c });
		else
			q.push({ {0,a + b},c });

		if (a + c > C)
			q.push({ {a + b - C, b},C });
		else
			q.push({ {0,b},a + c });

		if (b + a > A)
			q.push(make_pair(make_pair(A, b + a - A), c));
		else
			q.push(make_pair(make_pair(b + a, 0), c));

		if (b + c > C)
			q.push(make_pair(make_pair(a, b + c - C), C));
		else
			q.push(make_pair(make_pair(a, 0), b + c));

		if (c + a > A)
			q.push(make_pair(make_pair(A, b), c + a - A));
		else
			q.push(make_pair(make_pair(c + a, b), 0));

		if (c + b > B)
			q.push(make_pair(make_pair(a, B), c + b - B));
		else
			q.push(make_pair(make_pair(a, c + b), 0));
	}
}

int main(void)
{
	cin >> A >> B >> C;

	bfs();

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}