#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int parent[MAX];
float result;
vector<pair<float, float>> v[MAX];
vector<pair<float, pair<int, int>>> graph;

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
		return true;
	}
	return false;
}

int main(void)
{
	cin >> N;

	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 1;i <= N;i++) {
		float x, y;
		cin >> x >> y;
		v[i].push_back({ x,y });
	}

	for (int i = 1;i <= N;i++) {
		for (int j = i + 1;j <= N;j++) {
			float dist = sqrt(pow((v[i].front().first - v[j].front().first), 2) + pow((v[i].front().second - v[j].front().second), 2));
			graph.push_back({ dist,{i,j} });
		}
	}
	sort(graph.begin(), graph.end());
	for (int i = 0;i < graph.size();i++) {
		float dist = graph[i].first;
		int star1 = graph[i].second.first;
		int star2 = graph[i].second.second;

		if (Union(star1, star2)) {
			result += dist;
		}
	}
	cout.precision(3);
	cout << result;
}