#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 50+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, K, result;
int parent[MAX];
vector<int> know;
vector<int> party[MAX];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

bool Same(int A, int B)
{
	A = Find(A);
	B = Find(B);
	if (A == B)
		return true;
	return false;
}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 0;i < K;i++) {
		int a;
		cin >> a;
		know.push_back(a);
	}

	for (int i = 0;i < M;i++) {
		int num;
		cin >> num;
		for (int j = 0;j < num;j++) {
			int a;
			cin >> a;
			party[i].push_back(a);
		}
	}
	result = M;

	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 0;i < M;i++) {
		int num = party[i][0];
		for (int j = 1;j < party[i].size();j++) {
			Union(num, party[i][j]);
		}
	}

	for (int i = 0;i < M;i++) {
		bool flag = true;
		for (int j = 0;j < party[i].size();j++) {
			if (flag == false)
				break;

			int num1 = party[i][j];
			for (int k = 0;k < know.size();k++) {
				int num2 = know[k];
				if (Same(num1, num2) == true) {
					flag = false;
					break;
				}
			}
		}
		if (flag == false)
			result--;
	}
	cout << result;
}