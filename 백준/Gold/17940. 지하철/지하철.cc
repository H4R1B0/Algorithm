#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 1000+10
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
int color[MAX];
vector<pair<int, int>> v[MAX];

struct INFO
{
	int Cnt, Time, Cur;
};

struct cmp
{
	bool operator()(INFO a, INFO b) {
		if (a.Cnt == b.Cnt)
			return a.Time > b.Time;
		return a.Cnt > b.Cnt;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < N;i++)
		cin >> color[i];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int a;
			cin >> a;
			if (a != 0) {
				v[i].push_back({ j,a });
				v[j].push_back({ i,a });
			}
		}
	}

	vector<pair<int, int>> answer;
	priority_queue<INFO,vector<INFO>,cmp> pq;
	vector<int> dist(N, INF);
	pq.push({ 0,0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		int Cnt = pq.top().Cnt;
		int Time = pq.top().Time;
		int Cur = pq.top().Cur;
		pq.pop();
		if (Cur == M) {
			answer.push_back({ Cnt,Time });
		}

		if (dist[Cur] < Time)
			continue;
		for (int i = 0;i < v[Cur].size();i++) {
			int next = v[Cur][i].first;
			int nTime = v[Cur][i].second;
			if (dist[next] > Time + nTime) {	
				dist[next] = Time + nTime;
				if (color[next] != color[Cur]) {					
					pq.push({ Cnt + 1,dist[next] ,next });
				}
				else {					
					pq.push({ Cnt  ,dist[next] ,next });
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer[0].first << " " << answer[0].second;
}