#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 1000+1
#define INF 987654321
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M, K;
int arr[MAX];
int dp1[MAX];
int dp2[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> arr[i];
	for (int i = 1;i <= N;i++) {
		dp1[i] = 1;
		for (int j = 1;j <= i;j++) {
			if (arr[j] < arr[i] && dp1[i] < dp1[j] + 1)
				dp1[i] = dp1[j] + 1;
		}
	}
	for (int i = N;i >= 1;i--) {
		dp2[i] = 1;
		for (int j = N;j >= i;j--) {
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
				dp2[i] = dp2[j] + 1;
		}
	}
	int answer = 0;
	for (int i = 0;i <= N;i++) {
		answer = max(answer, dp1[i] + dp2[i]-1);
	}
	cout<<answer;
}