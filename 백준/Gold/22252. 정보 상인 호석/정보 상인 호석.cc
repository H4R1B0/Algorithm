#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, A, B;
map<string, priority_queue<ll>> dic;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	ll total = 0;
	for (int i = 0;i < N;i++) {
		int op, k;
		string name;
		cin >> op >> name >> k;
		if (op == 1) {
			for (int j = 0;j < k;j++) {
				ll a;
				cin >> a;
				dic[name].push(a);
			}
		}
		else if (op == 2) {
			for (int j = 0;j < k && !dic[name].empty();j++) {
				total += dic[name].top();
				dic[name].pop();
			}
		}
	}
	cout << total;
}