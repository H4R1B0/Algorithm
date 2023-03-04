#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int xd[] = { -2,-1,1,2,2,1,-1,-2 };
int yd[] = { 1,2,2,1,-1,-2,-2,-1 };

int N, K;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<vector<int>> g(N + 1, vector<int>(N + 1, INF));
	for (int i = 0;i < K;i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (g[i][k] && g[k][j]) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (g[i][j] > 6) {
				cout << "Big World!";
				return 0;
			}
		}
	}
	cout << "Small World!";
}