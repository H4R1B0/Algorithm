#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
vector<pair<int, int>> Coord;
vector<pair<int, int>> Connect;
vector<pair<double, pair<int, int>>> v;
int parent[MAX];
double result;


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

double Distance(int x, int y, int xx, int yy)
{
	double dx = pow(x - xx, 2);
	double dy = pow(y - yy, 2);
	double Dist = sqrt(dx + dy);

	return Dist;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}
	
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		Coord.push_back({ a,b });
	}
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		Connect.push_back({ a,b });
	}
	for (int i = 0;i < M;i++) {
		int N1 = Connect[i].first;
		int N2 = Connect[i].second;

		if (Find(N1) != Find(N2))
			Union(N1, N2);
	}
	
	for (int i = 0;i < N-1;i++) {
		int x = Coord[i].first;
		int y = Coord[i].second;

		for (int j = i+1;j < N;j++) {
			int xx = Coord[j].first;
			int yy = Coord[j].second;

			double Dist = Distance(x, y, xx, yy);
			v.push_back({ Dist, {i+1,j+1} });
		}
	}
	sort(v.begin(), v.end());
	
	for (int i = 0;i < v.size();i++) {
		if (Find(v[i].second.first) != Find(v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			result += v[i].first;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
}