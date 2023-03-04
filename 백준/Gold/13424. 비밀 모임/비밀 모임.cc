#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
//#define INF 10000000000
#define ll long long

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, M, K;
int dist[MAX][MAX];

void floyd() {
	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;

		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = INF;
			}
		}

		for (int i = 0;i < M;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			dist[a][b] = c;
			dist[b][a] = c;
		}
		floyd();

		vector<int> friends;
		cin >> K;
		for (int i = 1;i <= K;i++) {
			int a;
			cin >> a;
			friends.push_back(a);
		}

		int result = INF;
		int idx = 0;
		for (int i = 1;i <= N;i++) {
			int sum = 0;
			for (int j = 0;j < friends.size();j++) {
				sum += dist[i][friends[j]];
			}

			if (result > sum) {
				result = sum;
				idx = i;
			}
		}
		cout << idx << endl;
	}
}