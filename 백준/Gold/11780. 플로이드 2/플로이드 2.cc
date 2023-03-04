#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int map[MAX][MAX];
int route[MAX][MAX];
vector<int> v;

void floyd() {
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (i == j)
					continue;
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					route[i][j] = k;
				}
			}
		}
	}
}

void find_route(int Start, int End) {
	if (route[Start][End] == 0) {
		v.push_back(Start);
		v.push_back(End);
		return;
	}
	find_route(Start, route[Start][End]);
	v.pop_back();
	find_route(route[Start][End],End);
}

int main() {
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}
	floyd();
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (map[i][j] == INF)
				cout << 0 << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (map[i][j] == INF)
				cout << 0;
			else {
				v.clear();
				find_route(i, j);
				cout << v.size() << " ";
				for (int k = 0;k < v.size();k++)
					cout << v[k] << " ";
			}
			cout << endl;
		}
	}
}