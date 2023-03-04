#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 100000+1


int arr[MAX];
int dp[MAX];

int main() {
	
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	
	int result = 0;
	dp[0] = arr[0];
	result = dp[0];

	for (int i = 0;i < n;i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}

	cout << result;
}