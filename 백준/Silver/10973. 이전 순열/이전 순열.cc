#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 110

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N;

int main(void) {
	cin >> N;
	vector<int> v(N), arr(N);
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		v[i] = arr[i];
	}
	bool flag = false;
	do {
		if (flag) {
			for (int i = 0;i < v.size();i++)
				cout << v[i] << " ";
			return 0;
		}
		for (int i = 0;i < N;i++) {
			if (v[i] == arr[i])
				flag = true;
			else {
				flag = false;
				break;
			}
		}
	} while (prev_permutation(v.begin(), v.end()));
	cout << -1;
}