#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 1001


int arr[MAX];
int dp[MAX];

int main() {
	
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		dp[i] = 1;
	}
	int result = 0;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < i;j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(result, dp[i]);
	}
	cout << result;
}