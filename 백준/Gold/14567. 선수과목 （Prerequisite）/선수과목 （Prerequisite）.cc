#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int result[MAX];
int Entry[MAX];
vector<int> v[MAX];

int main() {
	cin >> N >> M;
		
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		Entry[b]++;
	}
	queue<int> q;
	for (int i = 1;i <= N;i++) {
		if (Entry[i] == 0)
			q.push(i);
		result[i] = 1;
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : v[cur]) {
			Entry[next]--;
			if (Entry[next] == 0) {
				q.push(next);
				result[next] = max(result[next], result[cur] + 1);
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		cout << result[i] << " ";
	}
}