#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

struct INFO {
	int x, y;
	vector<pair<int, int>> route;
};

int N, M;
int g[MAX][MAX];
bool tmp_visit[MAX][MAX];
int visit[MAX][MAX];
bool Aflag, Bflag, ansflag;
int Alen, Blen;
pair<int, int> A1, A2, B1, B2;

void bfs(int a, int b, int da, int db, char c) {
	queue<INFO> q;
	INFO tmp;
	tmp.x = a, tmp.y = b;
	tmp.route.push_back({ a,b });
	q.push(tmp);
	tmp_visit[a][b] = true;
	if (c == 'A')
		visit[a][b] = 1;
	else
		visit[a][b] = 2;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		vector<pair<int,int>> route = q.front().route;
		q.pop();

		if (x == da && y == db) {
			if (c == 'A') {
				Aflag = true;
				for (auto r : route) {
					visit[r.first][r.second] = 1;
					Alen++;
				}
			}
			else {
				Bflag = true;
				for (auto r : route) {
					visit[r.first][r.second] = 2;
					Blen++;
				}
			}
			return;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			vector<pair<int, int>> nroute = route;
			//cout << "ddd"<<nroute.size();

			if (nx >= 0 && nx <= N && ny >= 0 && ny <= M) {
				if (c == 'A') {
					if ((nx == B1.first && ny == B1.second) || (nx == B2.first && ny == B2.second))
						continue;
					if (tmp_visit[nx][ny] || visit[nx][ny])
						continue;
					tmp_visit[nx][ny] = true;
					nroute.push_back({ nx,ny });
					q.push({ nx,ny,nroute });
				}
				if (c == 'B') {
					if ((nx == A1.first && ny == A1.second) || (nx == A2.first && ny == A2.second))
						continue;
					if (tmp_visit[nx][ny] || visit[nx][ny])
						continue;
					tmp_visit[nx][ny] = true;
					nroute.push_back({ nx,ny });
					q.push({ nx,ny,nroute });
				}
			}

		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = INF;
	cin >> N >> M;
	cin >> A1.first >> A1.second;
	cin >> A2.first >> A2.second;
	cin >> B1.first >> B1.second;
	cin >> B2.first >> B2.second;

	bfs(A1.first, A1.second, A2.first, A2.second, 'A');
	memset(tmp_visit, false, sizeof(tmp_visit));
	bfs(B1.first, B1.second, B2.first, B2.second, 'B');

	if (Aflag && Bflag) {
		ansflag = true;
		ans = min(ans, Alen + Blen);
	}

	memset(tmp_visit, false, sizeof(tmp_visit));
	memset(visit, false, sizeof(visit));
	Alen = Blen = 0;
	Aflag = Bflag = false;
	bfs(B1.first, B1.second, B2.first, B2.second, 'B');
	memset(tmp_visit, false, sizeof(tmp_visit));
	bfs(A1.first, A1.second, A2.first, A2.second, 'A');
	if (Aflag && Bflag) {
		ansflag = true;
		ans = min(ans, Alen + Blen);
	}

	if (ansflag)
		cout << ans - 2;
	else
		cout << "IMPOSSIBLE";
}