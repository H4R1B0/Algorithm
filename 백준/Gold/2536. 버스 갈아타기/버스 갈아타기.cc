#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,1 };
int yd[] = { 1,0 };

struct BUS {
	int x1, y1, x2, y2;
};

struct LINE {
	int s, e, num;
};

int N, M, K;
int visit[5001];
vector<LINE> ho[100001], ve[100001];
BUS bus[5001];
pair<int, int> Start, End;

int bfs() {
	queue<int> q;
	for (auto v : ve[Start.first]) {
		if (Start.second >= v.s && Start.second <= v.e) {
			visit[v.num] = 1;
			q.push(v.num);
		}
	}
	for (auto v : ho[Start.second]) {
		if (Start.first >= v.s && Start.first <= v.e) {
			visit[v.num] = 1;
			q.push(v.num);
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		int x1 = bus[num].x1;
		int x2 = bus[num].x2;
		int y1 = bus[num].y1;
		int y2 = bus[num].y2;

		if (y1 == y2) {
			if (y1 == End.second && End.first >= x1 && End.first <= x2) {
				return visit[num];
			}
			for (int x = x1; x <= x2; x++)
				for (auto v : ve[x]) {
					if (!visit[v.num] && y1 >= v.s && y1 <= v.e) {
						visit[v.num] = visit[num] + 1;
						q.push(v.num);
					}
				}
			for (auto v : ho[y1]) {
				if (!visit[v.num] && x1 <= v.e && x2 >= v.s) {
					visit[v.num] = visit[num] + 1;
					q.push(v.num);
				}
			}
		}
		else {
			if (x1 == End.first && End.second >= y1 && End.second <= y2) {
				return visit[num];
			}
			for (int y = y1; y <= y2; y++)
				for (auto v : ho[y]) {
					if (!visit[v.num] && x1 >= v.s && x1 <= v.e) {
						visit[v.num] = visit[num] + 1;
						q.push(v.num);
					}
				}
			for (auto v : ve[x1]) {
				if (!visit[v.num] && y1 <= v.e && y2 >= v.s) {
					visit[v.num] = visit[num] + 1;
					q.push(v.num);
				}
			}
		}
	}
}


int main() {
	cin >> M >> N;
	cin >> K;
	for (int i = 0;i < K;i++) {
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);

		if (x1 == x2)
			ve[x1].push_back({ y1,y2,b });
		else if (y1 == y2)
			ho[y1].push_back({ x1,x2,b });
		bus[b] = { x1, y1, x2, y2 };
	}
	cin >> Start.first >> Start.second >> End.first >> End.second;

	cout << bfs();
}