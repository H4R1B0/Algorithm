#include <iostream>

using namespace std;


int main() {
	
	int arr[21] = {0,1,1,0};
	int n;
	cin >> n;

	for (int i = 3;i <= n;i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	cout << arr[n];
}