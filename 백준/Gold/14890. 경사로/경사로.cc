#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX (100+1)
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[] = { -1,0,1,0 };
int yd[] = { 0,1,0,-1 };

int N, L;
int MAP[MAX][MAX];
int answer;

bool check(vector<int> road, int idx) {
	int num = road[idx + 1];
	for (int i = idx + 1;i < idx + 1 + L;i++) {
		if (i >= N || road[i] != num)
			return false;
	}
	return true;
}

void solve(vector<int> road) {
	int cnt = 1;
	bool flag = true;
	for (int i = 0;i < road.size() - 1;i++) {
		if (road[i] == road[i + 1]) {
			cnt++;
		}
		//다음이 낮음
		else if (road[i] == road[i + 1] + 1) {
			if (check(road, i)) {
				i = i + L - 1;
				cnt = 0;
			}
			else {
				flag = false;
				break;
			}
		}
		//다음이 높음
		else if (road[i] + 1 == road[i + 1]) {
			if (cnt >= L)
				cnt = 1;
			else {
				flag = false;
				break;
			}
		}
		else if (abs(road[i] - road[i + 1]) >= 2) {
			flag = false;
			break;
		}
	}
	if (flag == true)
		answer++;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		vector<int> v;
		for (int j = 0;j < N;j++) {
			v.push_back(MAP[i][j]);
		}
		solve(v);
	}
	for (int i = 0;i < N;i++) {
		vector<int> v;
		for (int j = 0;j < N;j++) {
			v.push_back(MAP[j][i]);
		}
		solve(v);
	}
	cout << answer;
}