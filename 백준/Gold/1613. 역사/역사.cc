#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 400+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int n, k, s;
int map[MAX][MAX];
vector<pair<int, int>> want;

void floyd() {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (map[i][k] && map[i][k] == map[k][j])
					map[i][j] = map[i][k];
			}
		}
	}
	
}

int main(void)
{
	cin >> n >> k;
	for (int i = 0;i < k;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = -1;
		map[b][a] = 1;
	}
	cin >> s;
	for (int i = 0;i < s;i++) {
		int a, b;
		cin >> a >> b;
		want.push_back({ a,b });
	}
	floyd();
	for (int i = 0; i < want.size(); i++)
	{
		int a = want[i].first;
		int b = want[i].second;

		cout << map[a][b] << endl;
	}
}