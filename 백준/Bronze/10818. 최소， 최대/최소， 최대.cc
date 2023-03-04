#include <iostream>

using namespace std;


int main() {
	
	int N;
	int num;

	cin >> N;
	cin >> num;
	int min=num, max = num;
	for (int i = 1;i < N;i++) {
		cin >> num;
		if (min > num) {
			min = num;
		}
		if (max < num) {
			max = num;
		}
		
	}

	cout << min << " " << max;
}