#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int M, N;
int parent[MAX];
int total, result;
vector<pair<int, pair<int, int>>> V;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main(void)
{
	while (true) {
		V.clear();
		total = result = 0;
		for (int i = 0;i < MAX;i++)
			parent[i] = i;

		cin >> M >> N;
		if (M == 0 && N == 0)
			break;
		for (int i = 0;i < N;i++) {
			int x, y, z;
			cin >> x >> y >> z;
			total += z;
			V.push_back({ z,{x,y} });
		}
		sort(V.begin(), V.end());

		for (int i = 0;i < N;i++) {
			if (Find(V[i].second.first) != Find(V[i].second.second)) {
				Union(V[i].second.first, V[i].second.second);
				result += V[i].first;
			}
		}
		cout << total - result << endl;
	}
}