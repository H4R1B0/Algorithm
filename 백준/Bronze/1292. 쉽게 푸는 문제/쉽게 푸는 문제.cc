#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	int arr[1001];
	int a, b;
	int num = 0, sum = 0;;
	cin >> a >> b;
	for (int i = 1;i < 100;i++) {
		for (int j = 0;j < i;j++) {
			if (num > b) {
				for (int k = a-1;k < b;k++) {
					sum += arr[k];
				}
				cout << sum;
				return 0;
			}

			arr[num] = i;
			num++;
		}
	}
}