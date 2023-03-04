#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N;
ll K;
struct node {
	int left, right;
};
node arr[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1;i <= N;i++)
		cin >> arr[i].left >> arr[i].right;
	cin >> K;

	int cur = 1;
	while (1) {
		if (arr[cur].left == -1 && arr[cur].right == -1)
			break;
		else if (arr[cur].left == -1)
			cur = arr[cur].right;
		else if (arr[cur].right == -1)
			cur = arr[cur].left;
		else if (K % 2) {
			cur = arr[cur].left;
			K = K / 2 + 1;
		}
		else {
			cur = arr[cur].right;
			K = K / 2;
		}
	}
	cout << cur;
}