#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 3000+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, K;
vector<int> p_v;
vector<int> m_v;
vector<char> op_v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	int idx = 0;
	int m_cnt = 0;
	for (int i = 0;i < s.length();i++) {		
		if (s[i] == '+' || s[i] == '-') {
			if (m_cnt==0) {
				string num = s.substr(idx, i - idx);
				p_v.push_back(stoi(num));
			}
			else {
				string num = s.substr(idx, i - idx);
				m_v.push_back(stoi(num));
			}
			if (s[i] == '-')
				m_cnt++;
			idx = i + 1;
		}
	}
	if (m_cnt == 0) {
		string num = s.substr(idx, s.length() - idx);
		p_v.push_back(stoi(num));
	}
	else {
		string num = s.substr(idx, s.length() - idx);
		m_v.push_back(stoi(num));
	}
	int sum = 0;
	for (auto i : p_v) {
		//cout << i << " ";
		sum += i;
	}
	for (auto i : m_v) {
		//cout << i << " ";
		sum -= i;
	}
	cout << sum;
}