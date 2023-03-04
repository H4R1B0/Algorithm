#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 26+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };

int N, M;
int g[MAX][MAX];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();
	for (int i = 0;i < N;i++) {
		string s;
		getline(cin, s);
		//cout << s.length();
		g[s[0] - 'a'][s[s.size()-1] - 'a'] = 1;
	}

	for (int k = 0;k < MAX;k++) {
		for (int i = 0;i < MAX;i++) {
			for (int j = 0;j < MAX;j++) {
				if (g[i][k] && g[i][k] == g[k][j])
					g[i][j] = g[i][k];
			}
		}
	}

	cin >> M;
	cin.ignore();
	for (int i = 0;i < M;i++) {
		string s;
		getline(cin, s);
		if (g[s[0] - 'a'][s[5] - 'a'])
			cout << 'T' << endl;
		else
			cout << 'F' << endl;
	}
}