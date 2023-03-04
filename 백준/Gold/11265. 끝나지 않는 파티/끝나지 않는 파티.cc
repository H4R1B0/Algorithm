#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

int N, M;
int map[MAX][MAX];


int main() {
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> map[i][j];
		}
	}

	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b] <= c)
			cout << "Enjoy other party" << endl;
		else
			cout << "Stay here" << endl;
	}
}