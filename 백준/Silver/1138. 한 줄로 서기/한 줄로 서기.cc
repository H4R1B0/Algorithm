#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 10

int N;
int arr[MAX];

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		int left;
		cin >> left;

		for (int j = 0;j < N;j++) {
			if (left == 0 && arr[j] == 0) {
				arr[j] = i + 1;
				break;
			}
			else if(arr[j]==0)
				left--;
		}
	}

	for (int i = 0;i < N;i++) {
		cout << arr[i] << " ";
	}
}