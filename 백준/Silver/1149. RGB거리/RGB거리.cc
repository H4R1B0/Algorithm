#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001


int arr[MAX][3];
int result[MAX][3];

int main() {

	int N;
	cin >> N;

	for (int i = 1;i <= N;i++) {
		int a, b, c;
		cin >> a >> b >> c;

		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;
	}

	for (int i = 1;i <= N;i++) {
		result[i][0] = min(result[i - 1][1], result[i - 1][2]) + arr[i][0];
		result[i][1] = min(result[i - 1][0], result[i - 1][2]) + arr[i][1];
		result[i][2] = min(result[i - 1][0], result[i - 1][1]) + arr[i][2];
	}

	cout << min(min(result[N][0], result[N][1]), result[N][2]);
}