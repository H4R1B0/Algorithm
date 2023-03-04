#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int Time[MAX], tmp[MAX], arr[MAX];
vector<int> A[MAX];
queue<int> q;

int main(void)
{
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int a, b, c;
		cin >> a >> b;
		tmp[i] = Time[i] = a;
		for (int j = 0;j < b;j++) {
			cin >> c;
			A[c].push_back(i);
			arr[i]++;
		}
	}
	for (int i = 1;i <= N;i++)
		if (arr[i] == 0)
			q.push(i);

	int ans = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0;i < A[cur].size();i++) {
			int next = A[cur][i];

			Time[next] = max(Time[next], tmp[next] + Time[cur]);

			arr[next]--;

			if (arr[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1;i <= N;i++) {
		ans = max(ans, Time[i]);
	}
	cout << ans;
}