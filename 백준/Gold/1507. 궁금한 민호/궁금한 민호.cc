#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 21+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int map[MAX][MAX];
bool road[MAX][MAX];
int result;

void floyd() {
	for (int k = 0;k < N;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (i == j || j == k || i == k)
					continue;
				else if (map[i][j] > map[i][k] + map[k][j]) {
					result = -1;
					return;
				}
				else if (map[i][j] == map[i][k] + map[k][j]) {
					road[i][j] = false;
				}
			}
		}
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}
	memset(road, true, sizeof(road));
	floyd();

	if (result == -1) {
		cout << result << endl;
		return 0;
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (road[i][j])
				result += map[i][j];
		}
	}
	cout << result/2 << endl;
}