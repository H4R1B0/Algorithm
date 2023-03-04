#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { -1,0,1,0 };
int yd[4] = { 0,1,0,-1 };

int N, K, L;
int MAP[MAX][MAX];
vector<pair<int, char>> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;
	cin >> K;
	while (K--) {
		int a, b;
		cin >> a >> b;
		MAP[a-1][b-1] = 1;
	}
	cin >> L;
	while (L--) {
		int a;
		char b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	deque<pair<int, int>> q;
	int x = 0, y = 0, dir = 1, answer = 0, idx = 0;
	q.push_back({ x,y });
	MAP[x][y] = 2;

	while (true) {
		int nx = x + xd[dir];
		int ny = y + yd[dir];
		answer++;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || MAP[nx][ny] == 2)
			break;
		else if (MAP[nx][ny] == 0) {
			q.push_front({ nx,ny });
			MAP[nx][ny] = 2;
			MAP[q.back().first][q.back().second] = 0;
			q.pop_back();
		}
		else if (MAP[nx][ny] == 1) {
			MAP[nx][ny] = 2;
			q.push_front({ nx,ny });
		}

		if (idx < v.size()) {
			if (answer == v[idx].first) {
				if (v[idx].second == 'L')
					dir = (dir + 3) % 4;
				else
					dir = (dir + 1) % 4;
				idx++;
			}
			
		}
		x = nx;
		y = ny;
	}
	cout << answer;
}