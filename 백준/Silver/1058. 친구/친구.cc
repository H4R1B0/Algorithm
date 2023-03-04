#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 50
#define INF 987654321

int N;
int arr[MAX][MAX];

void floyd() {
	for (int i = 0;i < N;i++) {
		for (int a = 0;a < N;a++) {
			for (int b = 0;b < N;b++) {
				if (a == b || a == i || i == b) {
					continue;
				}
				arr[a][b] = min(arr[a][b], arr[a][i] + arr[i][b]);
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0;j < tmp.length();j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = tmp[j] == 'Y' ? 1 : INF;
			}
		}
	}

	floyd();

	int result = 0;

	for (int i = 0;i < N;i++) {
		int cnt = 0;
		for (int j = 0;j < N;j++) {
			if (i == j) {
				continue;
			}
			else if(arr[i][j]<=2){
				cnt++;
			}
		}
		result = max(result, cnt);
	}

	cout << result << endl;
}