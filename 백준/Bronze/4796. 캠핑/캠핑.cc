#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 300000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int L, P, V;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int idx = 1;;idx++) {
		cin >> L >> P >> V;
		if (!L && !P && !V)
			break;

		int ans = (V / P) * L + min(V % P, L);
		cout << "Case " << idx << ": " << ans << endl;
	}
}