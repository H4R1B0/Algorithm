#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

#define endl '\n'
#define MAX 100000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, X;
unordered_set<int> s;
vector<int> D, G;
priority_queue<int,vector<int>,greater<int>> D_pq, G_pq;

bool isPrime(int num) {
	if (num == 1 || num == 0)
		return false;
	int mid = (int)sqrt(num);
	for (int i = 2;i <= mid;i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	ll answerD = 0, answerG=0;
	while (N--) {
		int d, g;
		cin >> d;

		if (isPrime(d) == false) {
			if (G_pq.size() < 3) {
				answerG += 1000;
			}
			else {
				answerG += G_pq.top();
			}
		}
		else {
			if (s.count(d) > 0) {
				answerD -= 1000;
			}
			else {
				s.insert(d);
				if (D_pq.size() < 3)
					D_pq.push(d);
				else {
					D_pq.push(d);
					D_pq.pop();
				}
			}
		}

		cin >> g;
		if (isPrime(g) == false) {
			if (D_pq.size() < 3) {
				answerD += 1000;
			}
			else {
				answerD += D_pq.top();
			}
		}
		else {
			if (s.count(g) > 0) {
				answerG -= 1000;
			}
			else {
				s.insert(g);
				if (G_pq.size() < 3)
					G_pq.push(g);
				else {
					G_pq.push(g);
					G_pq.pop();
				}
			}
		}
	}

	if (answerD > answerG)
		cout << "소수의 신 갓대웅";
	else if (answerD < answerG)
		cout << "소수 마스터 갓규성";
	else
		cout << "우열을 가릴 수 없음";
}