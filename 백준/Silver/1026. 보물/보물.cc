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
vector<int> A, B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0;i < N;i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}

	int sum = 0;
	for (int i = 0;i < N;i++) {
		int Min_idx = min_element(A.begin(), A.end()) - A.begin();
		int Min = *min_element(A.begin(), A.end());
		int Max_idx = max_element(B.begin(), B.end()) - B.begin();
		int Max = *max_element(B.begin(), B.end());
		sum += Min * Max;
		A.erase(A.begin() + Min_idx);
		B.erase(B.begin() + Max_idx);
	}
	cout << sum;
}