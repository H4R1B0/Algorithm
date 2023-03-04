#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int T;
int N, M;


int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;

		for (int i = 0;i < M;i++) {
			int a, b;
			cin >> a >> b;
		}

		cout << N-1 << endl;
	}
}