#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int main() {
	
	int M, N;
	int sum = 0;
	int min=0;
	cin >> M>>N;
	for (int i = M;i <= N;i++) {
		if (sosu(i)) {
			sum += i;
			if (min == 0) {
				min = i;
			}
		}
		
	}

	if (sum == 0)
		cout << -1;
	else {
		cout << sum<<endl;
		cout << min;
	}
}