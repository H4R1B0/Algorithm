#include <iostream>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
queue<pair<int, int>> q;
vector<int> sumvec;
int xd[] = { 0,1,0,-1 };
int yd[] = { 1,0,-1,0 };
int m, n, k;
int num = 0;
void bfs(int x, int y)
{
	int sum = 0;
	arr[x][y] = 2;
	q.push({ x,y });

	while (q.size() > 0)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		sum++;

		for (int i = 0; i < 4; i++) {
			int nextX = x + xd[i];
			int nextY = y + yd[i];

			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && arr[nextX][nextY] == 0) {
				arr[nextX][nextY] = 2;
				q.push({ nextX,nextY });
			}
		}
	}
	sumvec.push_back(sum);
	num++;

}
int main() {
	int x1, y1, x2, y2;
	memset(arr, 0, sizeof(arr));
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				arr[y][x] = 1;
			}
		}

	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				bfs(i, j);
		}
	}

	cout << num << endl;
	sort(sumvec.begin(), sumvec.end());
	for (int i = 0; i < (int)sumvec.size(); i++) {
		cout << sumvec[i] << " ";
	}
}