#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
string map[MAX];
int height[MAX][MAX];
pair<int, int> Start;
bool visit[MAX][MAX];
vector<pair<int, int>> House;
vector<int> Height_v;

void dfs(int x, int y, int left, int right) {
	int result = 0;
	if (height[x][y] < left || height[x][y] > right)
		return;
	visit[x][y] = true;

	for (int i = 0;i < 8;i++) {
		int nx = x + xd[i];
		int ny = y + yd[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visit[nx][ny]) {
				if (height[nx][ny] >= left && height[nx][ny] <= right) {
					visit[nx][ny] = true;
					dfs(nx, ny, left, right);
				}
			}
		}
	}
}

int Solve() {
	int Left_num = 0, Right_num = 0;
	int result = INF;
	while (1) {
		if (Right_num == Height_v.size())
			break;
		while (1) {
			int cnt = 0;
			memset(visit, false, sizeof(visit));
			dfs(Start.first, Start.second, Height_v[Left_num], Height_v[Right_num]);
			for (int i = 0;i < House.size();i++) {
				if (visit[House[i].first][House[i].second]) {
					cnt++;
				}
			}
			if (cnt != House.size())
				break;
			result = min(result, Height_v[Right_num] - Height_v[Left_num]);
			Left_num++;
		}
		Right_num++;
	}
	return result;
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> map[i];
		for (int j = 0;j < N;j++) {
			if (map[i][j] == 'P') {
				Start = { i,j };
			}
			else if (map[i][j] == 'K') {
				House.push_back({ i,j });
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> height[i][j];
			Height_v.push_back(height[i][j]);
		}
	}
	sort(Height_v.begin(), Height_v.end());
	Height_v.erase(unique(Height_v.begin(), Height_v.end()), Height_v.end());
	cout << Solve();
}