#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 51

int T;
int N, M;
int arr[MAX];
vector<int> v;


int main() {

	cin >> N;
	int a;
	for (int i = 0;i < N;i++) {
		cin >> a;
		v.push_back(a);
	}

	if (N == 1) {
		cout << v[0] * v[0];
	}
	else {
		sort(v.begin(), v.end());
		cout << v.front() * v.back();
	}
}