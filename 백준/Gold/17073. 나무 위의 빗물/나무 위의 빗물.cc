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
#define MAX 500000+1
//#define INF 987654321
#define INF 10000000000
#define ll long long

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
double W, water[MAX];
vector<int> v[MAX];
bool visit[MAX];

int main() {
	cin >> N >> W;
	water[1] = W;
	for (int i = 0;i < N - 1;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int cnt = 0;
	queue<int> q;
	visit[1] = true;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		bool flag = false;

		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
				flag = true;
			}			
		}
		if (!flag)
			cnt++;
	}

	cout.precision(11);
	cout << W / cnt;
}