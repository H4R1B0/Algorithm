#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 100+1
#define INF 987654321
#define ll long long

int xd[4] = { 0,-1,0,1 };
int yd[4] = { 1,0,-1,0 };

int N, R, M, K;
map<string, int> city;
vector<string> travel;
vector<vector<double>> Tdist;
vector<vector<double>> Ndist;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R;

	Tdist.resize(N, vector<double>(N, INF));
	Ndist.resize(N, vector<double>(N, INF));
	for (int i = 0;i < N;i++) {
		Tdist[i][i] = 0;
		Ndist[i][i] = 0;
	}

	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		city[s] = i;
	}
	cin >> M;
	for (int i = 0;i < M;i++) {
		string s;
		cin >> s;
		travel.push_back(s);
	}
	cin >> K;
	for (int i = 0;i < K;i++) {
		string traffic, Start, End;
		double cost;
		cin >> traffic >> Start >> End >> cost;
		int Start_idx = city[Start];
		int End_idx = city[End];

		Tdist[Start_idx][End_idx] = min(Tdist[Start_idx][End_idx], cost);
		Tdist[End_idx][Start_idx] = min(Tdist[End_idx][Start_idx], cost);

		if (traffic == "S-Train" || traffic == "V-Train") {
			cost /= 2;
		}
		else if (traffic == "ITX-Saemaeul" || traffic == "ITX-Cheongchun" || traffic == "Mugunghwa") {
			cost = 0;
		}
		Ndist[Start_idx][End_idx] = min(Ndist[Start_idx][End_idx], cost);
		Ndist[End_idx][Start_idx] = min(Ndist[End_idx][Start_idx], cost);
	}

	for (int k = 0;k < N;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				Tdist[i][j] = min(Tdist[i][j], Tdist[i][k] + Tdist[k][j]);
				Ndist[i][j] = min(Ndist[i][j], Ndist[i][k] + Ndist[k][j]);
			}
		}
	}

	double general = 0, discount = 0;
	for (int i = 0;i < M - 1;i++) {
		string Start_city = travel[i];
		string End_city = travel[i + 1];
		int Start = city[Start_city];
		int End = city[End_city];

		general += Tdist[Start][End];
		discount += Ndist[Start][End];
	}
	if (general <= discount + R)
		cout << "No";
	else
		cout << "Yes";
}