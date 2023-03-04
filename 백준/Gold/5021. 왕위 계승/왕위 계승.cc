#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define endl '\n'
#define MAX 200000+1
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M;
struct INFO
{
	string s;
	double num;
	int count;
};

struct cmp
{
	bool operator()(INFO a, INFO b) {
		if (a.num == b.num)
			return a.count > b.count;
		return a.num < b.num;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, double> dic;
	map<string, int> cnt;
	cin >> N >> M;
	string s;
	cin >> s;
	dic[s] = 1;
	for (int i = 0;i < N;i++) {
		string a, b, c;
		cin >> a >> b >> c;
		dic[a] = dic[b] + dic[c];
		dic[a] /= 2;
		cnt[b]++;
		cnt[c]++;
		cnt[a] = (cnt[b] + cnt[c]) / 2;
	}
	priority_queue<INFO,vector<INFO>,cmp> pq;
	for (int i = 0;i < M;i++) {
		string s;
		cin >> s;
		pq.push({ s,dic[s],cnt[s] });
	}
	cout << pq.top().s;
}