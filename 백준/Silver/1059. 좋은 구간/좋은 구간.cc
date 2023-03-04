#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 51

int L;
vector<int> v;


int main() {

	cin >> L;
	int a;
	for (int i = 0;i < L;i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int n;
	cin >> n;

	int x=0, y=0;
	for (int i = 0;i < L;i++) {
		if (n > v[i]) {
			x = v[i];
		}
		else if (n < v[i]) {
			y = v[i];
			break;
		}
		else if (n == v[i]) {
			cout << "0" << endl;
			return 0;
		}
	}
	x++;
	y--;
	int result = (n - x) * (y - n + 1) + (y - n);

	cout << result;
}