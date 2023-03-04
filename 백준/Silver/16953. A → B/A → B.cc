#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000000000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int A, B;


int main() {
	cin >> A >> B;

	int cnt = 0;
	while (1) {
		if (A > B) {
			cout << -1 << endl;
			break;
		}
		if (A == B) {
			cout << cnt + 1 << endl;
			break;
		}
		if (B % 10 == 1) {
			B /= 10;
		}
		else if (B % 2 == 0) {
			B /= 2;
		}
		else {
			cout << -1 << endl;
			break;
		}
		cnt++;
	}
}