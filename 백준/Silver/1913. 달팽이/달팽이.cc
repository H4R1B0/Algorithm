#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 1000
#define endl '\n'

int xd[] = { 0,1,0,-1 };
int yd[] = { 1,0,-1,0 };

int N, M;
int MAP[MAX][MAX];

int main(void) {
	cin >> N >> M;
	int answer[2] = {0,0};
	int mid = (N - 1) / 2;
	MAP[mid][mid] = 1;
	int num = 2;
	int x = mid - 1, y = mid;
	int dir = 0;
	for (int i = 1;i <= mid;i++) {
		int top[2] = { mid - i,mid - i };
		int bottom[2] = { mid + i,mid + i };
		int cnt = (2 * i + 1) * (2 * i + 1) - (2 * i - 1) * (2 * i - 1);
		while (cnt--) {
			//cout << x << " " << y << endl;
			MAP[x][y] = num;			
			x += xd[dir];
			y += yd[dir];
			if (x<top[0] || x>bottom[0] || y<top[1] || y>bottom[1]) {
				x -= xd[dir];
				y -= yd[dir];
				dir = (dir + 1) % 4;
				x += xd[dir];
				y += yd[dir];
			}
			num++;
			if (cnt == 0) {
				x -= xd[dir];
				y -= yd[dir];
				dir = 3;
				x += xd[dir];
				y += yd[dir];
			}
				
		}
	}

	for (int i = 0;i < N;i++) {
		for(int j=0;j<N;j++){
			cout << MAP[i][j] << " ";
			if (MAP[i][j] == M)
				answer[0] = i, answer[1] = j;
		}
		cout << endl;
	}
	cout << answer[0]+1 << " " << answer[1]+1;
}