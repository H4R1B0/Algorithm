#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 3000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, K;
vector<int> arr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	int cnt = 0;
	int money = K;
	for (int i = N - 1;i >= 0;i--) {
		cnt += money / arr[i];
		money = money % arr[i];
	}
	cout << cnt;
}