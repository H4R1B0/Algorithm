#include <iostream>
#include <string>
using namespace std;


void ten_to_two_j(unsigned n, string& arr) {
	if (n < 2) { // n==1 (이전 n이 2이거나 3)
		arr += to_string(n);
		//printf("%d", n);
	}
	else {
		ten_to_two_j(n / 2, arr);
		arr += to_string(n % 2);
		//printf("%d", n % 2);
	}
}

int main() {
	
	
	int T, n;
	cin >> T;
	//scanf("%d", &T);
	for (int i = 0;i < T;i++) {
		string arr = "";
		cin >> n;
		//scanf("%d", &n);
		//itoa(n, arr, 2);
		ten_to_two_j(n,arr);
		//cout << arr;
		int num = arr.length() - 1;
		for (int j = num;j >= 0;j--) {
			
			if (arr[j] == '1') {
				cout << num - j<<" ";
				//printf("%d ", num - j);
			}
		}
		cout << endl;
		//printf("\n");
	}
}