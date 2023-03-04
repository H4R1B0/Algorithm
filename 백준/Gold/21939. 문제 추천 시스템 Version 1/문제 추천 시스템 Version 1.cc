#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M;
struct hard_cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};
struct easy_cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> level;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, hard_cmp> hard_pq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, easy_cmp> easy_pq;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		level[a] = b;
		hard_pq.push({ a,b });
		easy_pq.push({ a,b });
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		string s;
		int a, b;
		cin >> s;
		if (s == "add") {
			cin >> a >> b;
			level[a] = b;
			hard_pq.push({ a,b });
			easy_pq.push({ a,b });
		}
		else if (s == "recommend") {
			cin >> a;
			if (a == 1) {
				while (level[hard_pq.top().first] != hard_pq.top().second) {
					hard_pq.pop();
				}
				cout << hard_pq.top().first << endl;
			}				
			else if (a == -1) {
				while (level[easy_pq.top().first] != easy_pq.top().second) {
					easy_pq.pop();
				}
				cout << easy_pq.top().first << endl;
			}
		}
		else if (s == "solved") {
			cin >> a;
			level[a] = 0;
		}
	}
}