#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 1100
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, K;

int main(void) {
	vector<pair<int, int>> v;
	cin >> K;
	int EW = 0, NS = 0;
	for (int i = 0;i < 6;i++) {
		int dir, dist;
		cin >> dir >> dist;
		v.push_back({ dir,dist });
		if (dir >= 3)
			NS += dist;
		else
			EW += dist;
	}
	NS /= 2;
	EW /= 2;
	int idx = -1;
	for (int i = 0;i < 6;i++) {
		if (v[i].second == NS && v[(i + 1) % 6].second == EW) {
			idx = i;
			break;
		}
		if (v[i].second == EW && v[(i + 1) % 6].second == NS) {
			idx = i;
			break;
		}
	}

	int x = (idx + 3) % 6;
	int y = (idx + 4) % 6;
	cout << (NS * EW - (v[x].second * v[y].second)) * K;
}