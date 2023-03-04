#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N;
int parent[MAX];
bool visit[MAX];

int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		memset(visit, false, sizeof(visit));
		for (int i = 1;i <= N;i++)
			parent[i] = i;

		int a, b;
		for (int i = 0;i < N - 1;i++) {			
			cin >> a >> b;
			parent[b] = a;
		}
		cin >> a >> b;
		visit[a] = true;
		while (a != parent[a]) {
			a = parent[a];
			visit[a] = true;
		}
		while (1) {
			if (visit[b]) {
				cout << b << endl;
				break;
			}
			b = parent[b];
		}
	}
}