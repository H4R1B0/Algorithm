#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 11

int T;
int arr[MAX];
bool visit[MAX];

int main() {
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	cin >> T;

	for (int i = 4;i < MAX;i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	
	for (int i = 0;i < T;i++) {
		int a;
		cin >> a;
		cout << arr[a] << endl;
	}
}