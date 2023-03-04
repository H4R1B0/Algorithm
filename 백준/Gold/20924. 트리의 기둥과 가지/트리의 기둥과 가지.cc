#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, R;
bool visit[MAX];
vector<pair<int, int>> v[MAX];

pair<int,int> getlen(int cur, int len) {
	visit[cur] = true;
	if (v[cur].size() > 2)
		return { cur,len };
	if (v[R].size() == 2)
		return { cur,len };

	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i].first;
		int cost = v[cur][i].second;
		if (visit[next])
			continue;
		return getlen(next, cost + len);
	}
	return { cur,len };
}

int dfs(int cur, int len) {
	visit[cur] = true;
	if (v[cur].size() == 1)
		return len;

	int ret = 0;
	for (int i = 0;i < v[cur].size();i++) {
		int next = v[cur][i].first;
		int cost = v[cur][i].second;
		
		if (visit[next])
			continue;
		ret = max(ret, dfs(next, cost+len));
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R;
	for (int i = 0;i < N-1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	pair<int,int> ans1 = getlen(R, 0);
	int giganode = ans1.first;
	//cout << giganode << endl;
	int gigalen = ans1.second;
	//cout << giganode << endl;
	cout << gigalen << " " << dfs(giganode, 0);
}