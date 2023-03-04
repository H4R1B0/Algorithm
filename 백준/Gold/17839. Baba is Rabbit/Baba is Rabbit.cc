#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;
vector<string> answer;
map<string, vector<string>> dic;
map<string, bool> visit;

void dfs(string s) {
	if (visit[s])
		return;
	visit[s] = true;
	answer.push_back(s);
	vector<string> x = dic[s];
	for (auto i : x) {
		dfs(i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		string a, b, c;
		cin >> a >> b >> c;
		dic[a].push_back(c);
		visit[a] = false;
	}
	
	vector<string> x = dic["Baba"];
	for (auto i : x) {
		dfs(i);
	}
	sort(answer.begin(), answer.end());
	for (auto i : answer) {
		cout << i << endl;
	}
}