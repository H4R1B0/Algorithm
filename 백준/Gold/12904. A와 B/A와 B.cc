#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 55
#define endl '\n'

int xd[] = { -1,-1,0,1,1,1,0,-1 };
int yd[] = { 0,1,1,1,0,-1,-1,-1 };

string S, T;

int main(void) {
	cin >> S >> T;
	int answer = 0;
	while (1) {
		if (S.length() == T.length()) {
			if (S == T) {
				answer = 1;
				break;
			}
		}
		if (T.size() == 0)
			break;

		if (T.back() == 'A')
			T.pop_back();
		else{
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	cout << answer;
}