#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 200+1

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int R, C, N;
int map[MAX][MAX];

void Boom(vector<pair<int, int>> v) {
	for (int i = 0;i < v.size();i++) {
		int x = v[i].first;
		int y = v[i].second;
		map[x][y] = 0;

		for (int k = 0;k < 4;k++) {
			int nx = x + xd[k];
			int ny = y + yd[k];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				map[nx][ny] = 0;
			}
		}
	}
}

int main() {
	cin >> R >> C >> N;
	for (int i = 0;i < R;i++) {
		string str;cin >> str;
		for (int j = 0;j < str.length();j++) {
			if (str[j] == '.') {
				map[i][j] = 0;
			}
			else if (str[j] == 'O') {
				map[i][j] = 1;
			}
		}
	}

	for (int n = 0;n < N - 1;n++) {
		if (n % 2 == 0) {
			for (int i = 0;i < R;i++) {
				for (int j = 0;j < C;j++) {
					map[i][j]++;
				}
			}
		}
		else {
			for (int i = 0;i < R;i++) {
				for (int j = 0;j < C;j++) {
					map[i][j]++;
				}
			}
			vector<pair<int, int>> v;
			for (int i = 0;i < R;i++) {
				for (int j = 0;j < C;j++) {
					if (map[i][j] >= 3) {
						v.push_back({ i,j });
					}
				}
			}
			Boom(v);
		}
	}

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (map[i][j] != 0)
				cout << 'O';
			else
				cout << '.';
		}
		cout << endl;
	}
}