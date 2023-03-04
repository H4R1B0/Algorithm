#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 100001

int C, N;
int arr[MAX];
vector<pair<int, int>> v;


int main() {
	cin >> C >> N;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0;i < v.size();i++) {
		for (int k = 1;k <= MAX;k++) {
			if (k - v[i].first >= 0) {
				arr[k] = max(arr[k], arr[k - v[i].first] + v[i].second);
			}
		}
	}

	for(int i=1;i<=MAX;i++)
		if (arr[i] >= C) {
			cout << i;
			return 0;
		}
}