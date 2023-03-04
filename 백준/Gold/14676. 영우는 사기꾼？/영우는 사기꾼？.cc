#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, M, K;
int Entry[MAX];
int Build[MAX];
vector<int> v[MAX];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		Entry[b]++;
		v[a].push_back(b);
	}

	for (int i = 0;i < K;i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			if (Entry[b] == 0) {
				Build[b]++;
				if (Build[b] == 1) {
					for (int i = 0;i < v[b].size();i++) {
						Entry[v[b][i]]--;
					}
				}
			}
			else {
				cout << "Lier!" << endl;
				return 0;
			}
		}
		else {
			if (Build[b] > 0) {
				Build[b]--;
				if (Build[b] == 0) {
					for (int i = 0;i < v[b].size();i++) {
						Entry[v[b][i]]++;
					}
				}
			}
			else {
				cout << "Lier!" << endl;
				return 0;
			}
		}
	}
	cout << "King-God-Emperor" << endl;
}