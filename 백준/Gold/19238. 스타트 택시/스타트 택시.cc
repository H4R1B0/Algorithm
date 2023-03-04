#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 25
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

struct CUSTOMER {
	int x;
	int y;
	int Dest_x;
	int Dest_y;
};
struct INFO {
	int x;
	int y;
	int Dist;
	int Num;
};

int N, M, Fuel;
int map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> Taxi;
CUSTOMER Customer[MAX * MAX];

bool bfs(int a, int b, int c, int d, int Num) {
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(a, b), make_pair(0, Fuel)));
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int fuel = q.front().second.second;
		q.pop();

		if (x == c && y == d) {
			Fuel = Fuel - dist;
			Fuel = Fuel + (dist * 2);
			Taxi.first = x;
			Taxi.second = y;
			return true;
		}
		if (fuel == 0)
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
				if (map[nx][ny] != -1 && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(dist + 1, fuel - 1)));
				}
			}
		}
	}
	return false;
}

bool Info_Cmp(INFO a, INFO b)
{
	if (a.Dist == b.Dist) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else return a.x < b.x;
	}
	else return a.Dist < b.Dist;
}


int Find_Customer() {
	memset(visit, false, sizeof(visit));
	//x,y,dist,fuel
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {Taxi.first,Taxi.second}, {0,Fuel} });
	visit[Taxi.first][Taxi.second] = true;
	vector<INFO> v;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int fuel = q.front().second.second;
		q.pop();

		if (map[x][y] >= 1)
			v.push_back({ x,y,dist,map[x][y] });
		if (fuel == 0)
			continue;
		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
				if (map[nx][ny] != -1 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ {nx,ny}, {dist + 1,fuel - 1} });
				}
			}
		}
	}

	if (v.size() == 0)
		return -1;
	sort(v.begin(), v.end(), Info_Cmp);
	map[v[0].x][v[0].y] = 0;
	Fuel -= v[0].Dist;
	return v[0].Num;
}

int main(void)
{
	cin >> N >> M >> Fuel;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
	}

	cin >> Taxi.first >> Taxi.second;

	for (int i = 1;i <= M;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Customer[i] = { a,b,c,d };
		map[a][b] = i;
	}

	for (int i = 0;i < M;i++) {
		int num = Find_Customer();
		if (num == -1) {
			cout << -1 << endl;
			return 0;
		}bool Move = bfs(Customer[num].x, Customer[num].y, Customer[num].Dest_x, Customer[num].Dest_y, num);
		if (Move == false)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << Fuel << endl;
}