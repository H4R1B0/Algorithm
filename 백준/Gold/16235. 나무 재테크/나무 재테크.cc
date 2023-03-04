#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 11

int xd[] = { -1,-1,-1,0,0,1,1,1 };
int yd[] = { -1,0,1,-1,1,-1,0,1 };

struct info
{
	int x, y, z;
};

int N, M, K;
vector <int> tree[11][11];
int MAP[11][11];
int A[11][11];

int main(void) {
	cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> A[i][j];
			MAP[i][j] = 5;
		}
	}
	for (int i = 0;i < M;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	while (K--) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				sort(tree[i][j].begin(), tree[i][j].end());
				bool flag = false;
				for (int num = 0;num < tree[i][j].size();num++) {
					if (MAP[i][j] >= tree[i][j][num] && !flag) {
						MAP[i][j] -= tree[i][j][num];
						tree[i][j][num]++;
					}
					else {
						flag = true;
						MAP[i][j] += tree[i][j][num] / 2;
						tree[i][j].erase(tree[i][j].begin() + num);
						num--;
						M--;
					}
				}
			}
		}
		if (M == 0)
			break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int num = 0; num < tree[i][j].size(); num++) {
					if (tree[i][j][num] % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int nx = i + xd[k];
							int ny = j + yd[k];
							if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
								tree[nx][ny].push_back(1);
								M++;
							}							
						}
					}
				}
				MAP[i][j] += A[i][j];
			}
		}
	}
	cout << M;
}