#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

#define endl '\n'
#define MAX 1000000+10
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
int visit[MAX];
vector<int> gold;

void solve(int num) {
	if (num == 0)
		return;
	solve(visit[num]);
	cout << num - visit[num] << " ";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N;
	for (int i = 2;i < 128;i++) {
		vector<int> bi;
		string tmps;
		int tmp = i;
		while (tmp) {
			bi.push_back(tmp % 2);
			tmp /= 2;
		}
		for (int j = bi.size() - 1;j >= 0;j--) {
			if (j == bi.size() - 1)
				continue;
			if (bi[j] == 0)
				tmps += "4";
			else
				tmps += "7";
		}
		gold.push_back(stoi(tmps));
	}
	memset(visit, -1, sizeof(visit));
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == N)
			break;
		for (int i = 0;i < gold.size();i++) {
			int next = cur + gold[i];
			if (next > N)
				continue;
			if (visit[next] == -1) {
				visit[next] = cur;
				q.push(next);
			}
		}
	}
	if (visit[N] == -1) {
		cout << -1;
		return 0;
	}
	solve(N);
}