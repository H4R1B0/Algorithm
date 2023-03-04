#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
int Entry[MAX];
vector<int> v[MAX];

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		vector<int> tmp;
		int num;
		cin >> num;
		for (int j = 0;j < num;j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		for (int j = 0;j < tmp.size();j++) {
			for (int k = j + 1;k < tmp.size();k++) {
				v[tmp[j]].push_back(tmp[k]);
				Entry[tmp[k]]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1;i <= N;i++)
		if (!Entry[i])
			q.push(i);

	vector<int> result;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		result.push_back(num);

		for (int i = 0;i < v[num].size();i++) {
			int next = v[num][i];
			Entry[next]--;

			if (!Entry[next])
				q.push(next);
		}
	}

	if (result.size() != N)
		cout << 0;
	else
		for (int i = 0;i < result.size();i++)
			cout << result[i] << endl;
}