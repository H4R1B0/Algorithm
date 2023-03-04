#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 10
#define endl '\n'

int xd[] = { 0,1,0,-1 };
int yd[] = { -1,0,1,0 };

int N;

long long cal(long long num) {
    if (num % 4 == 0)
		return num;
    if (num % 4 == 1)
		return (num - 1) ^ num;
	if (num % 4 == 2)
		return ((num - 2) ^ (num - 1)) ^ num;
	if (num % 4 == 3)
		return 0;
}

int main(void) {
	long long a, b;
	cin >> a >> b;
	cout << (cal(a - 1) ^ cal(b));
	
}