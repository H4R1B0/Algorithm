#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 4000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int Friend[MAX];
bool check[MAX][MAX];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		Friend[a] += 1;
		Friend[b] += 1;
		check[a][b] = true;
		check[b][a] = true;
	}

	int ans = INF;
	for (int a = 1;a <= N;a++) {
		for (int b = a + 1;b <= N;b++) {
			if (check[a][b]) {
				for (int c = b + 1;c <= N;c++) {
					if (check[a][c] && check[b][c]) {
						int sum = Friend[a] + Friend[b] + Friend[c] - 6;
						ans = min(ans, sum);
					}
				}
			}
		}
	}
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
}