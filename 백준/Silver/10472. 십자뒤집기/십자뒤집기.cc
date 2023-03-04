#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>

#define endl "\n"
#define MAX 3+1
#define INF 987654321
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
vector<int> v[9] = {
	{0,1,3},{0,1,2,4},{1,2,5},
	{0,3,4,6},{1,3,4,5,7},{2,4,5,8},
	{3,6,7},{4,6,7,8},{5,7,8}
};

int bfs(string s) {
	queue<string> q;
	set<string> visit;
	q.push("000000000");
	visit.insert("000000000");
	int cnt = 1;
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			string cur = q.front();
			q.pop();

			for (int i = 0;i < 9;i++) {
				string next = cur;
				for (int j = 0;j < v[i].size();j++) {
					if (next[v[i][j]] == '1')
						next[v[i][j]] = '0';
					else
						next[v[i][j]] = '1';
				}
				if (visit.find(next) != visit.end())
					continue;
				if (s == next)
					return cnt;
				q.push(next);
				visit.insert(next);
			}
		}
		cnt++;
	}
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		string str = "";
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				char c;
				cin >> c;
				if (c == '*')
					str += "1";
				else
					str += "0";
			}
		}
		if (str == "000000000")
			cout << 0 << endl;
		else
			cout << bfs(str)<<endl;
	}
}
