#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 501

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M, B;

int main(void) {
	cin >> N;
	queue<int> q;
	for (int i = 1;i <= N;i++)
		q.push(i);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
		if (q.empty())
			break;
		q.push(q.front());
		q.pop();
	}		
}