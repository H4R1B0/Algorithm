#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 501
#define endl '\n'

int xd[] = { -1,1,0,0 };
int yd[] = { 0,0,1,-1 };

int N, M, B;

int main(void) {
	cin >> N;
	vector<int> arr(N+1);
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			for (int j = 1;j <= N;j++) {
				if (j % b == 0)
					arr[j] = !arr[j];
			}
		}
		else {
			for (int j = 1;j <= N;j++) {
				if (b - j >= 1 && b + j <= N && arr[b-j]==arr[b+j]) {
					continue;
				}
				else {
					j--;
					for(int k=b-j;k<=b+j;k++)
						arr[k] = !arr[k];
					break;
				}
			}
		}
	}
	for (int i = 1;i <= N;i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0)
			cout << endl;
	}
		
}