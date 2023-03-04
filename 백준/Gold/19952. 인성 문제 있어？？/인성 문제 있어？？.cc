#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, O, F;
struct INFO
{
	int x, y, power;
};
pair<int, int> Start, End;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M >> O >> F >> Start.first >> Start.second >> End.first >> End.second;
		vector<vector<int>> MAP(N + 1, vector<int>(M + 1, 0));
		vector<vector<bool>> visit(N + 1, vector<bool>(M + 1, false));
		for (int i = 0;i < O;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			MAP[a][b] = c;
		}
		bool flag = true;
		queue<INFO> q;
		q.push({ Start.first,Start.second,F });
		visit[Start.first][Start.second] = true;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int power = q.front().power;
			q.pop();
			
			if (x == End.first && y == End.second && power>=0) {
				flag = false;
				break;
			}

			for (int i = 0;i < 4;i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
					if (!visit[nx][ny]) {
						if (MAP[nx][ny] <= MAP[x][y]) {
							visit[nx][ny] = true;
							q.push({ nx,ny,power - 1 });
						}
						else if (MAP[nx][ny] > MAP[x][y] && (MAP[nx][ny] - MAP[x][y]) <= power) {
							visit[nx][ny] = true;
							q.push({ nx,ny,power - 1 });
						}
					}
				}
			}
		}
		if (!flag) {
			cout << "잘했어!!" << endl;
		}
		else {
			cout << "인성 문제있어??" << endl;
		}
	}
	
}