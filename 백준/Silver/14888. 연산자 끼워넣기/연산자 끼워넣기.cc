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
#define MAX 1000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N;
ll Max = -1000000001, Min = 1000000001;

void dfs(ll num, int cnt, vector<int> numbers, vector<int> ops) {
	if (cnt == N) {
		Max = max(Max, num);
		Min = min(Min, num);
		return;
	}

	for (int i = 0;i < 4;i++) {
		if (ops[i] >= 1) {
			ops[i] -= 1;
			if (i == 0)
				dfs(num + numbers[cnt], cnt + 1, numbers, ops);
			else if(i == 1)
				dfs(num - numbers[cnt], cnt + 1, numbers, ops);
			else if (i == 2)
				dfs(num * numbers[cnt], cnt + 1, numbers, ops);
			else if (i == 3)
				dfs(num / numbers[cnt], cnt + 1, numbers, ops);
			ops[i] += 1;
		}
	}
}

vector<int> solution(vector<int> numbers, vector<int> ops) {
	dfs(numbers[0], 1, numbers, ops);
	vector<int> answer;
	answer.push_back(Max);
	answer.push_back(Min);
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> numbers;
	vector<int> ops;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	for (int i = 0;i < 4;i++) {
		int a;
		cin >> a;
		ops.push_back(a);
	}

	vector<int> answer = solution(numbers, ops);
	cout << answer[0] << endl << answer[1];
}