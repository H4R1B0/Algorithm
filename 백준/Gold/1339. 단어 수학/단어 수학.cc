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
vector<int> cnt(26);
pair<int, int> v[MAX];

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		int cal = 1;
		for (int j = s.length()-1;j >= 0;j--) {
			cnt[s[j] - 'A'] += cal;
			cal *= 10;
		}
	}
	sort(cnt.begin(), cnt.end(),cmp);
	int ans = 0;
	for (int i = 0;i < 10;i++) {
		ans += cnt[i] * (9 - i);
	}
	cout << ans;
}