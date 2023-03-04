#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 99+1
#define INF 987654321

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int N, M;
vector<int> heavy[MAX], light[MAX];
bool hvisit[MAX], lvisit[MAX];

int hdfs(int node) {
	int result = 1;

	for (int i = 0; i < heavy[node].size(); i++) {
		if (!hvisit[heavy[node][i]]) {
			hvisit[heavy[node][i]] = true;
			result += hdfs(heavy[node][i]);
		}
	}

	return result;
}

int ldfs(int node) {
	int result = 1;

	for (int i = 0; i < light[node].size(); i++) {
		if (!lvisit[light[node][i]]) {
			lvisit[light[node][i]] = true;
			result += ldfs(light[node][i]);
		}
	}

	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		heavy[a].push_back(b);
		light[b].push_back(a);
	}

	vector<bool> result(N + 1);
	for (int i = 1;i <= N;i++) {
		memset(hvisit, false, sizeof(hvisit));
		memset(lvisit, false, sizeof(lvisit));
		hvisit[i] = true;
		lvisit[i] = true;

		if (hdfs(i) > (N + 1) / 2)
			result[i] = true;
		if (ldfs(i) > (N + 1) / 2)
			result[i] = true;
	}
	int cnt = 0;
	for (int i = 1;i <= N;i++)
		if (result[i])
			cnt++;
	cout << cnt;
}