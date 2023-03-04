#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int map[MAX][MAX];
int result[MAX];
vector<int> ans;

void floyd() {
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (i == j)
					continue;
				map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
			}
		}
	}
}

int main(void)
{	
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			map[i][j] = INF;
		}
	}
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		map[a][b] = 1;
		map[b][a] = 1;
	}
	floyd();

	int point = INF;
	for (int i = 1;i <= N;i++) {
		int Max = 0;
		for (int j = 1;j <= N;j++) {
			if (i == j)
				continue;
			Max = max(Max, map[i][j]);
			result[i] = Max;			
		}
		point = min(point, result[i]);
	}
	for (int i = 1;i <= N;i++) {
		if (result[i] == point)
			ans.push_back(i);
	}
	cout << point << " " << ans.size() << endl;
	for (int i = 0;i < ans.size();i++) {
		cout << ans[i] << " ";
	}
}