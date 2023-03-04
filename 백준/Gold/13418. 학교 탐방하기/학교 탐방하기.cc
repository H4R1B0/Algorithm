#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

struct go {
	int x;
	int y;
	int z;
};
int n, m;
vector<go> v;
bool com1(go a, go b) {
	if (a.z < b.z) return true;
	return false;
}
bool com2(go a, go b) {
	if (a.z > b.z) return true;
	return false;
}
int parent[100100];
int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y)
		parent[x] = y;
}
int main() {
	scanf("%d%d", &n, &m);
	int fx, fy, fz;
	int cntmax = 0;
	int cntmin = 0;
	int vertex = 0;
	for (int i = 0; i < m + 1; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1 && y == 0) {
			fz = z;
			continue;
		}
		if (x == 0 && y == 1) {
			fz = z;
			continue;
		}
		v.push_back({ x,y,z });
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	//max
	if (fz == 0) cntmax++;
	Union(0, 1);
	sort(v.begin(), v.end(), com2);
	for (int i = 0; i < v.size(); i++) {
		int nowx = v.at(i).x;
		int nowy = v.at(i).y;
		int dist = v.at(i).z;
		if (Find(nowx) != Find(nowy)) {
			if (dist == 0)
				cntmax++;
			Union(nowx, nowy);
			vertex++;
		}
		if (vertex == n - 1) break;
	}
	int maxdist = cntmax * cntmax;

	if (fz == 0) cntmin++;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	Union(0, 1);
	sort(v.begin(), v.end(), com1);
	for (int i = 0; i < v.size(); i++) {
		int nowx = v.at(i).x;
		int nowy = v.at(i).y;
		int dist = v.at(i).z;
		if (Find(nowx) != Find(nowy)) {
			if (dist == 0)
				cntmin++;
			Union(nowx, nowy);
			vertex++;
		}
		if (vertex == n - 1) break;
	}
	int mindist = cntmin * cntmin;

	cout << mindist - maxdist << endl;


}