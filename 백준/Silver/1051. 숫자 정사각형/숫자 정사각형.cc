#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 51

int arr[MAX][MAX];

int N, M;

int maxS() {
	int result = 1;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			for (int k = 1;k < min(N, M);k++) {
				if (i + k < N && j + k < M && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i + k][j + k]) {
					result = max(result, k + 1);
				}
			}
		}
	}
	return result*result;
}

int main() {
	cin >> N>> M;
	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0;j < M;j++) {
			arr[i][j]=tmp[j]-'0';
		}
	}
	cout << maxS() << endl;
}