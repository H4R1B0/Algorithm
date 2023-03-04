#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0, 1, 1, 0, -1, -1 };
int yd[] = { 2, 1, -1, -2, -1, 1 };


int N, Start, End;
int jump[MAX];
int visit[MAX];

int bfs(vector<string> Start,vector<string> End) {
	set<vector<string>> visit;
	map<vector<string>, int> cnt;
	queue<vector<string>> q;

	visit.insert(Start);
	cnt[Start] = 0;
	q.push({ Start });

	while (!q.empty()) {
		vector<string> cur = q.front();
		q.pop();

		if (cur == End)
			return cnt[cur];

		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				if (i == j)
					continue;

				if (cur[i].size() == 0)
					continue;

				vector<string> next = cur;
				string from = next[i];
				string to = next[j];

				to += from[from.size() - 1];
				from.pop_back();

				next[i] = from;
				next[j] = to;

				if (visit.count(next)==0) {
					visit.insert(next);
					cnt[next] = cnt[cur] + 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	vector<string> stick(3, "");
	int A_num = 0, B_num = 0, C_num = 0;

	for (int i = 0;i < 3;i++) {
		int cnt;
		string str="";

		cin >> cnt;
		if (cnt != 0)
			cin >> str;

		for (int j = 0;j < cnt;j++) {
			if (str[j] == 'A')
				A_num++;
			else if (str[j] == 'B')
				B_num++;
			else if (str[j] == 'C')
				C_num++;
		}
		stick[i] = str;
	}

	vector<string> dest_stick(3, "");

	for (int i = 0;i < A_num;i++)
		dest_stick[0] += 'A';
	for (int i = 0;i < B_num;i++)
		dest_stick[1] += 'B';
	for (int i = 0;i < C_num;i++)
		dest_stick[2] += 'C';

	cout << bfs(stick, dest_stick);
}