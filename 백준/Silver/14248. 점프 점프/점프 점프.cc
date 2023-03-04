#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
int arr[MAX];
int visit[MAX];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	cin >> s;

	queue<int> q;
	q.push(s);
	visit[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int next = cur + arr[cur];
		if (next < MAX && !visit[next]) {
			visit[next] = visit[cur] + 1;
			q.push(next);
		}
		next = cur - arr[cur];
		if (next >= 1 && !visit[next]) {
			visit[next] = visit[cur] + 1;
			q.push({ next });
		}		
	}

	int ans = 0;
	for (int i = 1;i <= N;i++) {
		if (visit[i])
			ans++;
	}
	cout << ans;
}