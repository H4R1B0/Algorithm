#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 60+1
#define INF 987654321
//#define INF 10000000000
#define ll long long

//int xd[] = { 0,1 };
//int yd[] = { 1,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

struct INFO {
	int x, ADDH, ADDT, MINT, ADDO, MINO;
};

int N;
INFO pizza[MAX];
bool visit[MAX];
queue<INFO> q;

void push(INFO t) {
	if (t.x < 0 || 60 < t.x || visit[t.x])
		return;
	visit[t.x] = true;
	q.push(t);
	pizza[t.x] = t;
}

void bfs() {
	push({ 0,0,0,0,0 });

	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();

		push({ cur.x - 1,cur.ADDH,cur.ADDT,cur.MINT,cur.ADDO,cur.MINO + 1 });
		push({ cur.x + 1,cur.ADDH,cur.ADDT,cur.MINT,cur.ADDO + 1,cur.MINO });
		push({ cur.x - 10,cur.ADDH,cur.ADDT,cur.MINT + 1,cur.ADDO,cur.MINO });
		push({ cur.x + 10,cur.ADDH,cur.ADDT + 1,cur.MINT,cur.ADDO,cur.MINO });
		push({ cur.x + 60,cur.ADDH + 1,cur.ADDT,cur.MINT,cur.ADDO,cur.MINO });
	}
}

int main() {
	int T;
	cin >> T;
	bfs();
	while (T--) {
		cin >> N;
		int k = N % 60;
		cout << N / 60 + pizza[k].ADDH << " " << pizza[k].ADDT << " " << pizza[k].MINT << " " << pizza[k].ADDO << " " << pizza[k].MINO << endl;
	}
}