#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 11
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> person(N + 1);
		for (int i = 1;i <= N;i++) {
			cin >> person[i];
		}

		vector<int> count(N + 1);

		int next = person[1];
		for (int i = 1;;i++) {
			if (count[next] == 1) {
				cout << 0 << endl;
				break;
			}

			if (next == N) {
				cout << i << endl;
				break;
			}

			count[next]++;
			next = person[next];
		}
	}
}