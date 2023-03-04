#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

#define endl '\n'
#define MAX 101+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, result;
char map[MAX][MAX];
bool key[26];
bool visit[MAX][MAX];

void Initialize() {
	memset(key, false, sizeof(key));
	memset(visit, false, sizeof(visit));
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x < 0 || x > N+1 || y < 0 || y > M+1)
			continue;
		if (visit[x][y] || map[x][y] == '*' || (map[x][y] >= 'A' && map[x][y] <= 'Z'))
			continue;

		visit[x][y] = true;

		if (map[x][y] == '$') {
			result++;
			map[x][y] = '.';
		}
		if (map[x][y] >= 'a' && map[x][y] <= 'z') {
			char door = (char)toupper(map[x][y]);
			map[x][y] = '.';

			int num = (int)door - (int)'A';
			if (!key[num]) {
				key[num] = true;

				for (int a = 1;a <= N;a++) {
					for (int b = 1;b <= M;b++) {
						if (map[a][b] == door) {
							map[a][b] = '.';
						}
					}
				}
				memset(visit, false, sizeof(visit));
				while (!q.empty())
					q.pop();
				q.push({ x,y });
				continue;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			q.push(make_pair(nx, ny));
		}
	}
}

int main(void)
{
	//cout << (int)'A';
	int T;
	cin >> T;
	while (T--) {
		Initialize();

		cin >> N >> M;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= M;j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0;i <= N + 1;i++) {
			for (int j = 0;j <= M + 1;j++) {
				if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
					map[i][j] = '.';
				else continue;
			}
		}


		string str;
		cin >> str;
		for (int i = 0;i < str.length();i++) {
			if (str[i] == '0')
				break;
			//cout << "check ";

			int num = (int)str[i] - (int)'a';
			key[num] = true;
			for (int a = 1;a <= N;a++) {
				for (int b = 1;b <= M;b++) {
					if (map[a][b] == (char)toupper(str[i])) {
						map[a][b] = '.';
					}
				}
			}
		}

		result = 0;
		bfs(0, 0);
		cout << result << endl;
	}
}