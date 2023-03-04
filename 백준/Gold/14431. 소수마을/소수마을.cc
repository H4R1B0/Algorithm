#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
pair<int, int> Start, End;
bool isPrime(int num) {
	if (num == 0 || num == 1)
		return false;
	int mid = (int)sqrt(num);
	for (int i = 2;i <= mid;i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int getDistance(pair<int,int> a, pair<int,int> b) {
	return (int)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;	
	cin >> Start.first >> Start.second >> End.first >> End.second;
	cin >> N;
	vector<int> dist(N + 2,INF);
	v.push_back(Start);
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	v.push_back(End);

	vector<vector<pair<int, int>>> route(N + 2);
	for (int i = 0;i < N + 2;i++) {
		for (int j = 0;j < N + 2;j++) {
			if (i == j)
				continue;
			int distance = getDistance(v[i], v[j]);
			if (isPrime(distance)) {
				route[i].push_back({j,distance });
				route[j].push_back({i,distance });
			}
		}
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < route[cur].size();i++) {
			int next = route[cur][i].first;
			int ncost = cost+ route[cur][i].second;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
	if (dist[N + 1] == INF)
		cout << -1;
	else
		cout << dist[N + 1];
}