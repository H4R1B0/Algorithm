#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 500+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int result;
int map[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int a, int b) {	
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	int size = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == 1 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					size++;
				}
			}
		}
	}
	//cout << size << endl;
	result = max(result, size);
}

int main(void)
{
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> map[i][j];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}			
	}
	if (cnt == 0) {
		cout << 0<<endl<<0;
	}
	else {
		cout << cnt << endl << result;
	}
	
}