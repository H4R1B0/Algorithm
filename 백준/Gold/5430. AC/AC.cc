#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>
#include <deque>

using namespace std;

#define endl '\n'
#define MAX 13+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,1,0,-1 };
int yd[4] = { 1,0,-1,0 };

int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string p,str;
		deque<int> dq;
		bool reverse_flag = false, error_flag = false;
		cin >> p;
		cin >> N;
		cin >> str;
		string s = "";
		for (int i = 0;i < str.length();i++) {
			if (isdigit(str[i])) {
				s += str[i];
			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}
		for (auto i : p) {
			if (i == 'R')
				reverse_flag = !reverse_flag;
			else {
				if (dq.empty()) {
					cout << "error" << endl;
					error_flag = true;
					break;
				}
				if (reverse_flag)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if (error_flag)
			continue;
		cout << '[';
		if (reverse_flag && !dq.empty()) {
			for (auto i = dq.rbegin();i != dq.rend();i++) {
				if (i == dq.rend() - 1)
					cout << *i;
				else
					cout << *i << ',';
			}
		}
		else {
			for (auto i = dq.begin();i != dq.end();i++) {
				if (i == dq.end() - 1)
					cout << *i;
				else
					cout << *i << ',';
			}
		}
		cout << ']' << endl;
	}
}