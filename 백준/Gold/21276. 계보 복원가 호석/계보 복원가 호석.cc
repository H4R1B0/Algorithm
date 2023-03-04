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
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int Entry[MAX];
vector<int> v[MAX];
vector<int> ans[MAX];
map<string, int> person_num;
map<int, string> person_name;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		person_num[s] = i;
		person_name[i] = s;
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		string a, b;
		cin >> a >> b;
		v[person_num[b]].push_back(person_num[a]);
		Entry[person_num[a]]++;
	}

	vector<int> root;
	queue<int> q;
	for (int i = 0;i < N;i++) {
		if (Entry[i] == 0) {
			root.push_back(i);
			q.push(i);
		}			
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];

			Entry[next]--;
			if (Entry[next] == 0) {
				ans[cur].push_back(next);
				q.push(next);
			}
		}
	}

	cout << root.size() << endl;
	for (int i = 0;i < root.size();i++)
		cout << person_name[root[i]] << " ";
	cout << endl;
	for (int i = 0;i < N;i++) {
		cout << person_name[i] << " " << ans[i].size() << " ";
		sort(ans[i].begin(), ans[i].end());
		for (int a : ans[i]) {
			cout << person_name[i] << " ";
		}
		cout << endl;
	}
}