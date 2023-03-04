#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

#define endl '\n'
#define MAX 1000000+1
#define INF 987654321
#define ll long long

using namespace std;
int T, N, K, M;
int Parent[MAX];
vector<int> answer;

void Init() {
	answer.clear();
	for (int i = 0; i < MAX; i++) {
		Parent[i] = -1;
	}
}

int Find(int X) {
	if (Parent[X] == -1) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union_Group(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		Parent[P_Y] = P_X;
	}
}

void Input() {
	cin >> T;
	for (int i = 1; i <= T;i++) {
		Init();
		cin >> N;
		cin >> K;
		for (int i = 0; i < K; i++) {
			int A, B;
			cin >> A >> B;
			Union_Group(A, B);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int U, V;
			cin >> U >> V;
			if (Find(U) == Find(V)) {
				answer.push_back(1);
			}
			else {
				answer.push_back(0);
			}
		}
		cout << "Scenario " << i << ": \n";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
		cout << "\n";
	};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();

	return 0;
}