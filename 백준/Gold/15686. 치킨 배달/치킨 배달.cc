#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

#define endl '\n'
#define MAX 13+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
int answer = INF;
bool Select[MAX];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;

int caldist(pair<int, int> a, pair<int, int> b) {
	//cout<< abs(a.first - b.first) + abs(a.second - b.second);
	return abs(a.first - b.first) + abs(a.second- b.second);
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		int sum = 0;
		for (int i = 0;i < houses.size();i++) {
			int dist = INF;
			for (int j = 0;j < chickens.size();j++) {
				if (Select[j])
					dist = min(dist, caldist(houses[i], chickens[j]));
			}
			sum += dist;
		}
		//cout << sum;
		answer = min(answer, sum);
		return;
	}
	
	for (int i = idx;i < chickens.size();i++) {
		if (Select[i])
			continue;
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

int solution(vector<vector<int>> MAP) {
	//int answer = 0;
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			//cout << MAP[i][j];
			if (MAP[i][j] == 2) {
				//cout << 2;
				chickens.push_back({ i,j });
			}
			else if (MAP[i][j] == 1) {
				houses.push_back({ i,j });
			}
		}
	}
	dfs(0,0);
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//int N, M;
	cin >> N >> M;
	vector<vector<int>> MAP(N, vector<int>(N,0));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}
	//cout << MAP[0][2];
	int answer = solution(MAP);
	cout << answer;
}