#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 'z'-'A'+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N, M;
vector<vector<int>> v(MAX+1, vector<int>(MAX+1, INF));


int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		string a, x, b;
		cin >> a >> x >> b;
		v[a[0] - 'A' + 1][b[0] - 'A' + 1] = 1;
	}

	for (int i = 1; i <= MAX; i++) {
		v[i][i] = 0;
	}

	for (int k = 1; k <= MAX; k++) {
		for (int a = 1; a <= MAX; a++) {
			for (int b = 1; b <= MAX; b++) {
				if (v[a][k] != INF && v[k][b] != INF) {
					v[a][b] = min(v[a][b], v[a][k] + v[k][b]);
				}
			}
		}
	}

	int cnt = 0;
	for (int a = 1; a <= MAX; a++) {
		for (int b = 1; b <= MAX; b++) {
			if ((v[a][b] != INF) && (v[a][b] != 0))
				cnt++;
		}
	}
	cout << cnt << endl;

	for (int a = 1; a <= MAX; a++) {
		for (int b = 1; b <= MAX; b++) {
			if ((v[a][b] != INF) && (v[a][b] != 0))
				cout << (char)(a + 'A' - 1) << " => " << (char)(b + 'A' - 1) << "\n";
		}
	}
}