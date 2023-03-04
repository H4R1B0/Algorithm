#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N;
int v[MAX];
bool visit[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++) {
		int a;
		cin >> a;
		v[i] = a;
	}

	int meet = 1;
	int idx = 1;
	for (int i = 1;i <= N;i++) {
		memset(visit, false, sizeof(visit));

		int cur = i;
		int cnt = 0;
		while (!visit[cur]) {
			visit[cur] = true;
			cur = v[cur];
			cnt++;
		}

		if (cnt > meet) {
			meet = cnt;
			idx = i;
		}
	}

	cout << idx;
}