#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N;
pair<int, int> v[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		//vector<pair<int, int>> v;
		for (int i = 0;i < N;i++) {
			int a, b;
			cin >> a >> b;
			v[i] = { a,b };
		}
		sort(v, v+N);

		int cnt = 0;
		int Max = v[0].second;
		for (int i = 0;i < N;i++) {
			if (v[i].second <= Max) {
				cnt++;
				Max = v[i].second;
			}
		}
		cout << cnt << endl;
	}
}