#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	
	int n,sum=0;
	int arr[9];
	//cin >> n;
	for (int i = 0;i < 9;i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	//cout << sum;

	int num = sum - 100;
	for (int i = 0; i< 9;i++) {
		for (int j = i + 1;j < 9;j++) {
			if (arr[i] + arr[j] == num) {
				arr[i] = 0;
				arr[j] = 0;
				sort(arr, arr + 9);
				for (int k = 0;k < 9;k++) {
					if (arr[k] == 0)
						continue;
					cout << arr[k] << endl;
				}
				return 0;
			}
		}
	}
	
}