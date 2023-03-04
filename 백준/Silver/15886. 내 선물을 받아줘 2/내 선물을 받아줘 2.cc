#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 50000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;

int main() {
	cin >> N;
	string str;
	cin >> str;

	int cnt = 0;
	for (int i = 0;i < str.length() - 1;i++) {
		if (str[i] == 'E' && str[i + 1] == 'W')
			cnt++;
	}
	cout << cnt;
}