#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 2000
#define endl '\n'

int xd[] = { -1,-1,-1,0 };
int yd[] = { -1,0,1,1 };

int N, M, K;
int MAP[20][20];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

vector<pair<int, int>> check(int a, int b, int num) {
	
	for (int i = 0;i < 4;i++) {
		vector<pair<int, int>> v;
		for (int j = 0;;j++) {
			int nx = a + xd[i] * j;
			int ny = b + yd[i] * j;
			if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
				break;
			if (num != MAP[nx][ny])
				break;
			v.push_back({ nx,ny });
		}
		for (int j = 1;;j++) {
			int nx = a - xd[i] * j;
			int ny = b - yd[i] * j;
			if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
				break;
			if (num != MAP[nx][ny])
				break;
			v.push_back({ nx,ny });
		}
		if (v.size() == 5) {
			return v;
		}
	}
	return {};
}

int main(void) {
	for (int i = 0;i < 19;i++) {
		for (int j = 0;j < 19;j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0;i < 19;i++) {
		for (int j = 0;j < 19;j++) {
			if (MAP[i][j]) {
				vector<pair<int, int>> tmp = check(i, j, MAP[i][j]);
				if (tmp.size()==5) {
					sort(tmp.begin(), tmp.end(),cmp);
					cout << MAP[i][j] << endl;
					cout << tmp[0].first + 1 << " " << tmp[0].second + 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
}