#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100000+1
//#define INF 987654321
#define INF 10000000000
#define ll long long

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K;

int bfs(string s) {
	queue<pair<string, int>> q;
	q.push({ s,0 });
	map<string, bool> visit;
	string target = s;
	sort(target.begin(), target.end());

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == target)
			return cnt;

		if (!visit[cur]) {
			visit[cur] = true;
			for (int i = 0;i <= N - K;i++) {
				string tmp = cur.substr(i, K);
				reverse(tmp.begin(), tmp.end());
				q.push({ cur.substr(0,i) + tmp + cur.substr(i + K,cur.size()),cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> K;
	string s;
	for (int i = 0;i < N;i++) {
		char c;
		cin >> c;
		s += c;
	}

	cout << bfs(s);
}