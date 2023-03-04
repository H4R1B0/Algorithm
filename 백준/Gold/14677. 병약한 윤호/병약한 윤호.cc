#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1500+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
bool visit[MAX][MAX];
string list = "BLD";
string p;

struct INFO
{
	int cur, l, r;
};

int bfs(int l, int r) {
	int answer = 0;
	queue<INFO> q;
	visit[l][r] = true;
	if (p[l] == list[0]) {
		q.push({ 0,l + 1,r });
		visit[l + 1][r] = true;
	}
	if (p[r] == list[0]) {
		q.push({ 0,l,r - 1 });
		visit[l][r - 1] = true;
	}
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			int cur = q.front().cur;
			int L = q.front().l;
			int R = q.front().r;
			q.pop();

			if (L > R)
				continue;
			if (p[L] == list[(cur + 1) % 3] && !visit[L+1][R]) {
				visit[L + 1][R] = true;
				q.push({ (cur + 1) % 3,L + 1,R });
			}
			if (p[R] == list[(cur + 1) % 3] && !visit[L][R-1]) {
				visit[L][R-1] = true;
				q.push({ (cur + 1) % 3,L,R-1 });
			}
		}
		answer++;
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N;
	cin >> p;

	cout << bfs(0, 3 * N - 1);
}