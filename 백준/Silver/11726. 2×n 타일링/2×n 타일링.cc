#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001

int arr[MAX];

int main() {

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3;i < MAX;i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 10007;
	}
	int n;

	cin >> n;
	cout << arr[n] << endl;
}