#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N, M, T, S, G, H, Dist_GH;
int Dist_S[MAX];
int Dist_G[MAX];
int Dist_H[MAX];

vector<pair<int, int>> V[MAX];
vector<int> Candidate;

void Initialize() {
	for (int i = 0; i < MAX; i++) {
		V[i].clear();
		Dist_S[i] = INF;
		Dist_G[i] = INF;
		Dist_H[i] = INF;
	}
	Candidate.clear();
}

void dijkstra(int Start, int A[MAX]) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,Start });
	A[Start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0;i < V[cur].size();i++) {
			int next = V[cur][i].first;
			int ncost = V[cur][i].second;

			if (A[next] > cost + ncost) {
				A[next] = cost + ncost;
				pq.push({ -A[next],next });
			}
		}
	}
}

int main(void)
{
	int Tc;
	cin >> Tc;
	while (Tc--) {
		Initialize();

		cin >> N >> M >> T;
		cin >> S >> G >> H;
		for (int i = 0;i < M;i++) {
			int a, b, d;
			cin >> a >> b >> d;
			V[a].push_back({ b,d });
			V[b].push_back({ a,d });
		}
		for (int i = 0;i < T;i++) {
			int a;
			cin >> a;
			Candidate.push_back(a);
		}

		dijkstra(S, Dist_S);
		dijkstra(G, Dist_G);
		Dist_GH = Dist_G[H];
		dijkstra(H, Dist_H);
		sort(Candidate.begin(), Candidate.end());
		for (int i = 0;i < Candidate.size();i++) {
			int dest = Candidate[i];
			if (Dist_S[dest] == Dist_S[G] + Dist_GH + Dist_H[dest])
				cout << dest << " ";
			else if (Dist_S[dest] == Dist_S[H] + Dist_GH + Dist_G[dest])
				cout << dest << " ";
		}
		cout << endl;
	}
}