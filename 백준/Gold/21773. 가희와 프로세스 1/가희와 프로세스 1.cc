#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

#define endl '\n'
#define MAX (100+1)
#define INF 987654321
#define ll long long
#define mod 1000000007

int xd[] = { -1,0,1,0 };
int yd[] = { 0,1,0,-1 };

int N, M, T;
struct INFO
{
	int id, order, process_time;
};
struct cmp
{
	bool operator()(INFO a, INFO b) {
		if (a.order == b.order) {
			return a.id > b.id;
		}
		return a.order < b.order;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T >> N;
	priority_queue<INFO, vector<INFO>, cmp> pq;
	for (int i = 0;i < N;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,c,b });
	}
	while (T-- && !pq.empty()) {
		int id = pq.top().id;
		int order = pq.top().order;
		int process_time = pq.top().process_time;
		pq.pop();
		cout << id << endl;
		if (process_time > 1)
			pq.push({ id,order - 1,process_time - 1 });
	}
}