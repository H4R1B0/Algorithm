#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 41

int arr[MAX][MAX];

int main() {
	int n,T;
	int cnt = 0;
	cin >> T;
	for (int i = 0;i < T;i++) {
		cnt = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cin >> n;
		for (int j = 0;j < n;j++) {
			int cx, cy, r, d;
			bool in1, in2;

			cin >> cx >> cy >> r;

			d = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
			in1 = d > r * r ? false : true;
			d = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
			in2 = d > r * r ? false : true;
			if (in1 != in2) cnt++;
		}
		cout << cnt << endl;
	}
	
}