#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define endl "\n"
#define MAX 101

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int N;
int height;

int map[MAX][MAX];
bool visit[MAX][MAX];


void floyd() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (map[j][i] && map[i][k])
					map[j][k] = 1;
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	floyd();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}