#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N,M,K;

bool visit[MAX][MAX];

vector<vector<bool>> multiply(const vector<vector<bool>>& M1, const vector<vector<bool>>& M2) {
	vector<vector<bool>> ret(N + 1, vector<bool>(N + 1));
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				if (M1[i][k] && M2[k][j]) {
					ret[i][j] = true;
				}
			}
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> M;
	vector<vector<bool>> ans(N + 1, vector<bool>(N + 1));
	for (int i = 1;i <= N;i++)
		ans[i][i] = true;

	vector<vector<bool>> factor(N + 1, vector<bool>(N + 1));
	for (int i = 1;i <= N;i++) {
		int a, b;
		cin >> a >> b;
		factor[i][a] = true;
		factor[i][b] = true;
	}

	while (K) {
		if (K & 1) {
			ans = multiply(ans, factor);
			K--;
		}
		factor = multiply(factor, factor);
		K /= 2;
	}

	while (M--) {
		int x, y;
		cin >> x >> y;

		if (ans[x][y])
			cout << "death" << endl;
		else
			cout << "life" << endl;
	}
}