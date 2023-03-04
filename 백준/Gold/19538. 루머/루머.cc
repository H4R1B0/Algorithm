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
#define MAX 200000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M;
int person[MAX];
vector<int> v[MAX];
queue<int> q;


void bfs() {
	queue<int> nq;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (person[next] != -1)
				continue;
			int cnt = 0;
			for (int j = 0;j < v[next].size();j++) {
				if (person[v[next][j]] != -1)
					cnt++;
			}
			if (cnt * 2 >= v[next].size())
				nq.push(next);
		}

		if (q.empty()) {
			while (!nq.empty()) {
				int node = nq.front();
				nq.pop();
				person[node] = person[cur] + 1;
				q.push(node);
			}
		}
	}
}

int main() {
	cin >> N;
	
		
	for (int i = 1;i <= N;i++) {
		person[i] = -1;
		while (1) {
			int a;
			cin >> a;
			if (a == 0)
				break;
			v[i].push_back(a);
		}
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		int a;
		cin >> a;
		person[a] = 0;
		q.push(a);
	}
	bfs();

	for (int i = 1;i <= N;i++)
		cout << person[i] << " ";
}