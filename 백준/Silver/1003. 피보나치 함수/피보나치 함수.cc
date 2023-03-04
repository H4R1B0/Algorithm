#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 41

int arr[MAX][MAX];

int main() {
	int T;
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	for (int i = 2;i < MAX;i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}

	cin >> T;

	for (int i = 0;i < T;i++) {
		int a;
		cin >> a;
		cout <<arr[a][0] << " " << arr[a][1]<<endl;
	}
}