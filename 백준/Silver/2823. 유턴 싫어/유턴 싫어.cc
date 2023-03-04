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
#define MAX 10+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
string map[MAX];

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> map[i];
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == '.') {
				int cnt = 0;
				for (int k = 0;k < 4;k++) {
					int nx = i + xd[k];
					int ny = j + yd[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if(map[nx][ny]!='X')
							cnt++;
					}
				}
				if (cnt == 1) {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}