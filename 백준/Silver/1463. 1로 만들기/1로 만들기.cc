#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1000000+1

int N;
int map[MAX];
bool visit[MAX];

int main() {
	cin >> N;

	map[1] = 0;

	for (int i = 2;i <= N;i++) {
		map[i] = map[i - 1] + 1;
		if (i % 2 == 0)
			map[i] = min(map[i], map[i / 2] + 1);
		if (i % 3 == 0)
			map[i] = min(map[i], map[i / 3] + 1);
	}
	cout << map[N];
}