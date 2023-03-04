#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

string N;
int M, K;
int result;

void bfs(string str) {
	queue<string> q;
	q.push(str);
	int cnt = 0;
	int Max = 0;

	while (!q.empty() && cnt < K) {
		int qsize = q.size();
		set<string> visit;

		for (int qi = 0;qi < qsize;qi++) {
			string cur = q.front();
			q.pop();

			for (int i = 0;i < M - 1;i++) {
				for (int j = i + 1;j < M;j++) {
					if (i == 0 && cur[j] == '0')
						continue;

					swap(cur[i], cur[j]);
					if (visit.find(cur) == visit.end()) {
						if (cnt == K - 1 && Max < stoi(cur)) {
							Max = stoi(cur);
						}
						q.push(cur);
						visit.insert(cur);
					}
					swap(cur[i], cur[j]);
				}
			}
		}
		cnt++;
	}

	if (cnt != K)
		cout << -1 << endl;
	else
		cout << Max << endl;
}


int main(void)
{
	cin >> N >> K;
	M = N.length();
	if (M == 1 || (M == 2 && stoi(N) % 10 == 0)) {
		cout << -1 << endl;
		return 0;
	}
	bfs(N);
}