#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 20000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N;
bool visit[MAX];
pair<int, char> arr[MAX];

void bfs() {
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(1);

	arr[1].first = -1;
	arr[1].second = '1';
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int node[2];
		node[0] = (cur * 10 + 0) % N;
		node[1] = (cur * 10 + 1) % N;

		for (int i = 0;i < 2;i++) {
			if (visit[node[i]])
				continue;
			arr[node[i]].first = cur;
			arr[node[i]].second = i + '0';

			if (node[i] == 0)
				return;

			visit[node[i]] = true;
			q.push(node[i]);
		}
	}
	cout << "BRAK" << endl;
}
void printReverse(int parent) {
	if (parent == -1) return;      

	printReverse(arr[parent].first);
	cout << arr[parent].second;

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		bfs();
		printReverse(0);
		cout << endl;
	}
}