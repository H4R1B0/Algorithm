#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
struct INFO
{
	int D, H, row, num;
};

struct cmp
{
	bool operator()(INFO a, INFO b) {
		if (a.D == b.D) {
			if (a.H == b.H) {
				return a.row > b.row;
			}
			return a.H < b.H;
		}
		return a.D < b.D;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	vector<queue<INFO>> lines(M);
	priority_queue<INFO, vector<INFO>, cmp> pq;
	for (int i = 0;i < N;i++) {
		int D, H;
		cin >> D >> H;
		lines[i % M].push({ D,H,i % M,i });
	}

	for (int i = 0;i < M;i++) {
		if (lines[i].empty())
			continue;
		pq.push(lines[i].front());
		lines[i].pop();
	}

	int answer = 0;
	while (true) {
		if (pq.top().num == K)
			break;
		int cur = pq.top().row;
		pq.pop();
		answer++;
		if (lines[cur].empty())
			continue;
		pq.push(lines[cur].front());
		lines[cur].pop();
	}
	cout << answer;
}