#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 200+1
#define INF 987654321
//#define INF 10000000000
#define ll long long

//int xd[] = { 0,1 };
//int yd[] = { 1,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;

int main() {
	int T;
	cin >> T;
	int idx = 1;
	while (T--) {
		string a, b, c;
		cin >> a >> b >> c;
		int a_len = a.length();
		int b_len = b.length();
		vector<vector<bool>> memo(a_len + 1, vector<bool>(b_len + 1));
		memo[0][0] = true;
		for (int i = 1; i <= a_len; i++)
			memo[i][0] = (a[i - 1] == c[i - 1]) ? memo[i - 1][0] : false;
		for (int i = 1; i <= b_len; i++)
			memo[0][i] = (b[i - 1] == c[i - 1]) ? memo[0][i - 1] : false;
		for (int i = 1; i <= a_len; i++) {
			for (int j = 1; j <= b_len; j++) {
				char curA = a[i - 1], curB = b[j - 1], curC = c[i + j - 1];
				if (curA != curC && curB != curC)
					memo[i][j] = false;
				else if (curA == curC && curB != curC)
					memo[i][j] = memo[i - 1][j];
				else if (curA != curC && curB == curC)
					memo[i][j] = memo[i][j - 1];
				else
					memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
			}
		}

		if (memo[a_len][b_len]) {
			cout << "Data set " << idx++ << ": yes" << endl;
		}
		else {
			cout << "Data set " << idx++ << ": no" << endl;
		}
	}
}