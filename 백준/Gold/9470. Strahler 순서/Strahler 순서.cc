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

int K, M, P;
vector<int> river[MAX];
pair<int, int> result[MAX];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> K >> M >> P;

		for (int i = 0;i <= M;i++) {
			river[i].clear();
			result[i] = { 0,0 };
		}

		vector<int> Entry(M + 1);		
		for (int i = 0;i < P;i++) {
			int a, b;
			cin >> a >> b;
			river[a].push_back(b);
			Entry[b]++;
		}

		queue<int> q;
		for (int i = 1;i <= M;i++) {
			if (Entry[i] == 0) {
				q.push(i);
				result[i] = { 1,1 };
			}				
		}

		for (int i = 1;i <= M;i++) {
			int cur = q.front();
			q.pop();

			for (auto next : river[cur]) {
				if (result[next].first < result[cur].first)
					result[next] = { result[cur].first,1 };
				else if (result[next].first == result[cur].first)
					result[next].second++;

				Entry[next]--;
				if (Entry[next] == 0) {
					if (result[next].second > 1)
						result[next] = { result[next].first + 1,1 };
					q.push(next);
				}
			}
		}

		for (int i = 1;i <= M;i++)
			cnt = max(cnt, result[i].first);
		cout << K << " " << cnt << endl;
	}
}