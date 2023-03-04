#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
string s[1002], visit[1002];
map<string, int> m;
queue<int> q;
int N, K;
string bfs(int a, int b) {
	q.push(a);
	visit[a] = to_string(a);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		if (f == b) return visit[f];
		string s2 = s[f];
		for (int i = 0; i < K; i++) {
			if (s2[i] == '0') s2[i] = '1';
			else s2[i] = '0';
			if (m.find(s2) != m.end()) {
				int index = m.find(s2)->second;
				if (visit[index] == "") {
					visit[index] = visit[f] + " " + to_string(index);
					q.push(index);
				}
			}
			if (s2[i] == '0') s2[i] = '1';
			else s2[i] = '0';
		}
	}
	return "-1";
}
int main() {
	cin >> N >> K;
	int a, b;
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
		m.insert({ s[i], i });
	}
	cin >> a >> b;
	cout << bfs(a, b);
}