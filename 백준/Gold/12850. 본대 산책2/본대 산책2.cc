#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 8+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

long long D;

vector<vector<long long>> multiply(const vector<vector<long long>>& M1, const vector<vector<long long>>& M2) {
	vector<vector<long long>> ret(8, vector<long long>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			long long elem = 0;
			for (int k = 0; k < 8; k++) {
				elem += (M1[i][k] * M2[k][j]);
				elem %= 1000000007;
			}
			ret[i][j] = elem % 1000000007;
		}
	}
	return ret;
}

int main() {
	cin >> D;
	vector<vector<long long>> ans(8, vector<long long>(8));
	for (int i = 0;i < 8;i++)
		ans[i][i] = 1;
	vector<vector<long long>> factor = {
		{0, 1, 1, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 0, 0, 0},
		{1, 1, 0, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 1, 0, 0},
		{0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 1, 0}
	};

	while (D) {
		if (D & 1) {
			ans = multiply(ans, factor);
			D -= 1;
		}
		factor= multiply(factor, factor);
		D /= 2;
	}
	cout << ans[0][0];
}