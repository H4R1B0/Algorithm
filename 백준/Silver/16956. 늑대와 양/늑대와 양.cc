#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int R, C;
string map[MAX];

int main() {
	cin >> R >> C;
	for (int i = 0;i < R;i++)
		cin >> map[i];

	bool isSheep = false;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (map[i][j] == 'S') {
				for (int k = 0;k < 4;k++) {
					int nx = i + xd[k];
					int ny = j + yd[k];

					if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
						if (map[nx][ny] == 'W')
							isSheep = true;
					}
				}
			}
		}
	}

	if (isSheep)
		cout << 0 << endl;
	else {
		cout << 1 << endl;
		for (int i = 0;i < R;i++) {
			for (int j = 0;j < C;j++) {
				if (map[i][j] == 'S') {
					for (int k = 0;k < 4;k++) {
						int nx = i + xd[k];
						int ny = j + yd[k];

						if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
							if (map[nx][ny] == '.')
								map[nx][ny] = 'D';
						}
					}
				}
			}
		}

		for (int i = 0;i < R;i++)
			cout << map[i] << endl;
	}
}