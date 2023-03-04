#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 101+1
#define INF 987654321

int xd[4] = { -1, 0, 1, 0 };
int yd[4] = { 0, 1, 0, -1 };

int N;
vector<int> arr = {-1};

int main(void) {
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		if (a > arr.back()) {
			arr.push_back(a);
		}
		else {
			auto low = lower_bound(arr.begin(), arr.end(), a);
			*low = a;
		}
	}
	cout << arr.size()-1;
}