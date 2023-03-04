#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 1001

int N, L;
vector<int> v[MAX];
bool visit[MAX];

int main() {
	cin >> N >> L;

	for (int i = L;i <= 100;i++) {
		int tmp = N - i * (i + 1) / 2;
		if (tmp % i == 0) {
			int j = tmp / i + 1;

			if (j >= 0) {
				for (int k = 0;k < i;k++) {
					cout << k + j << " ";
				}
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}