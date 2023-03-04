#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 9999+2
#define INF 987654321

struct Node {
	int data;
	Node* left;
	Node* right;
};

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int T;
int N, M;
bool visit[MAX];

bool sosu(int num) {
	if (num < 2)
		return false;

	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++)
		if (num % i == 0)
			return false;
	return true;
}

void bfs() {
	queue<pair<int,int>> q;
	q.push({ N,0 });
	visit[N] = true;

	while(!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == M) {
			cout << cnt << endl;
			return;
		}

		for (int i = 1;i <= 9;i++) {
			int num1 = i * 1000 + cur % 1000;
			if (!visit[num1] && sosu(num1)) {
				visit[num1] = true;
				q.push({num1, cnt+1});
			}
		}

		for (int i = 0;i <= 9;i++) {
			int num2 = (cur / 1000) * 1000 + i * 100 + cur % 100;
			if (!visit[num2] && sosu(num2)) {
				visit[num2] = true;
				q.push({ num2, cnt + 1 });
			}
		}
		
		for (int i = 0;i <= 9;i++) {
			int num3 = (cur / 100) * 100 + i * 10 + cur % 10;
			if (!visit[num3] && sosu(num3)) {
				visit[num3] = true;
				q.push({ num3, cnt + 1 });
			}
		}

		for (int i = 0;i <= 9;i++) {
			int num4 = (cur / 10) * 10 + i;
			if (!visit[num4] && sosu(num4)) {
				visit[num4] = true;
				q.push({ num4, cnt + 1 });
			}
		}
	}
	cout << "Impossible" << endl;
	return;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(visit, false, sizeof(visit));
		bfs();
	}
}