#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 250+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];

void floyd() {
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (i == j)
					continue;
				map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i != j)
				map[i][j] = INF;
		}
	}
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = 0;
		if (c == 0)
			map[b][a] = 1;
		else
			map[b][a] = 0;
	}
	floyd();
	int T;
	int a, b;
	cin >> T;
	while (T--) {
		
		cin >> a >> b;
		cout << map[a][b] << endl;
	}
}