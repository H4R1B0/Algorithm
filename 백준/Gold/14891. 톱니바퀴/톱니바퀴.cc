#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX ()
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,-1,1 };
int yd[4] = { 1,-1,0,0 };

int N, K;
vector<int> Sawtooths[4];

//시계 방향
void Rotate1(int idx) {
	int a = Sawtooths[idx].back();
	Sawtooths[idx].pop_back();
	Sawtooths[idx].insert(Sawtooths[idx].begin(), a);
}
//반시계 방향
void Rotate2(int idx) {
	int a = Sawtooths[idx][0];
	Sawtooths[idx].erase(Sawtooths[idx].begin());
	Sawtooths[idx].push_back(a);
}

void cmd(int idx, int flag) {
	vector<pair<int, int>> v;
	vector<bool> visit(4, false);
	queue<pair<int, int>> q;
	q.push({ idx,flag });
	visit[idx] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int dir = q.front().second;
		q.pop();

		v.push_back({ cur,dir });

		int next = cur + 1;
		if (next >= 0 && next < 4 && !visit[next]) {
			visit[next] = true;
			if (Sawtooths[cur][2] != Sawtooths[next][6]) {
				q.push({ next,dir * (-1) });
			}
		}

		next = cur - 1;
		if (next >= 0 && next < 4 && !visit[next]) {
			visit[next] = true;
			if (Sawtooths[cur][6] != Sawtooths[next][2]) {
				q.push({ next,dir * (-1) });
			}
		}
	}

	for (auto i : v) {
		if (i.second == 1) {
			Rotate1(i.first);
		}
		else {
			Rotate2(i.first);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0;i < 4;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.length();j++) {
			Sawtooths[i].push_back(s[j] - '0');
		}
	}

	cin >> K;
	while (K--) {
		int a, b;
		cin >> a >> b;
		a--;
		cmd(a, b);
	}

	int answer = 0;
	answer += Sawtooths[0][0] == 0 ? 0 : 1;
	answer += Sawtooths[1][0] == 0 ? 0 : 2;
	answer += Sawtooths[2][0] == 0 ? 0 : 4;
	answer += Sawtooths[3][0] == 0 ? 0 : 8;
	cout << answer;
}