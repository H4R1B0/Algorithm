#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, D;
vector<int> v[MAX];

vector<vector<long long>> multiply(const vector<vector<long long>>& M1, const vector<vector<long long>>& M2) {
	vector<vector<long long>> ret(N + 1, vector<long long>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			long long elem = 0;
			for (int k = 1; k <= N; k++) {
				elem += (M1[i][k] * M2[k][j]);
				elem %= 1000000007;
			}
			ret[i][j] = elem % 1000000007;
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<vector<ll>> ans(N + 1, vector<ll>(N + 1));
	for (int i = 1;i <= N;i++)
		ans[i][i] = 1;

	vector<vector<ll>> factor(N + 1, vector<ll>(N + 1));

	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		factor[a][b] = 1;
		factor[b][a] = 1;
	}
	cin >> D;

	while (D) {
		if (D & 1) {
			ans = multiply(ans, factor);
			D -= 1;
		}
		factor = multiply(factor, factor);
		D /= 2;
	}

	cout << ans[1][1];
}