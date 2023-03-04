#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

string Start="", End = "123456780";
set<string> visit;

int bfs() {
	queue<pair<string, int>> q;
	q.push({ Start,0 });
	visit.insert(Start);

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == End) {
			return cnt;
		}

		int idx = cur.find('0');
		int x = idx / 3;
		int y = idx % 3;

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next = cur;
				swap(next[x * 3 + y], next[nx * 3 + ny]);

				if (visit.find(next) == visit.end()) {
					visit.insert(next);
					q.push({ next,cnt + 1 });
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			int num;
			cin >> num;
			char tmp = num + '0';
			Start += tmp;
		}
	}
	cout << bfs();
}