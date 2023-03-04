#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 101+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, result;

int main(void) {
	string s;
	cin >> s;
	int answer = 0;
	while (1) {
		if (s.length() == 1)
			break;
		int sum = 0;
		for (int i = 0;i < s.length();i++) {
			sum += (s[i] - '0');
		}
		s = to_string(sum);
		answer++;
	}
	cout << answer << endl;
	if (s == "3" || s == "6" || s == "9")
		cout << "YES";
	else
		cout << "NO";
}