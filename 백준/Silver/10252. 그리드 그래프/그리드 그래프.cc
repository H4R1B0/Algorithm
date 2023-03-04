#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int i = 0, j = 0;
		cout << 1 << endl;
		while (1) {
			cout << '(' << i << ',' << j << ')' << endl;
			if (i % 2)
				j--;
			else
				j++;
			if (j >= M || j < 1) {
				i++;
				if (i % 2)
					j--;
				else
					j++;
			}
			if (i == N)
				break;
		}
		for (int i = N - 1;i > 0;i--) {
			cout << '(' << i << ',' << 0 << ')' << endl;
		}
	}
}