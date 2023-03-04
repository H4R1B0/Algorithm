#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 10000+1

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int Start, End, Road_Cnt;
int Entry[MAX], Time[MAX];
bool Visit[MAX];
vector<pair<int, int>> Road[MAX], R_Road[MAX];

void Find_Dist(int S) {
	queue<pair<int, int>> q;
	q.push({ S,0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cur_time = q.front().second;
		q.pop();

		for (int i = 0;i < Road[cur].size();i++) {
			int next = Road[cur][i].first;
			int ntime = Road[cur][i].second;

			Time[next] = max(Time[next], cur_time + ntime);
			Entry[next]--;

			if (Entry[next] == 0)
				q.push({ next,Time[next] });
		}
	}
}

void Find_Road(int E) {
	queue<int> q;
	q.push(E);
	Visit[E] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < R_Road[cur].size();i++) {
			int prev = R_Road[cur][i].first;
			int prevtime = R_Road[cur][i].second;

			if (Time[cur] - prevtime == Time[prev]) {
				Road_Cnt++;
				if (!Visit[prev]) {
					Visit[prev] = true;
					q.push(prev);
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Road[a].push_back({ b,c });
		R_Road[b].push_back({ a,c });
		Entry[b]++;
	}
	cin >> Start >> End;
	Find_Dist(Start);
	Find_Road(End);
	cout << Time[End] << endl << Road_Cnt;
}