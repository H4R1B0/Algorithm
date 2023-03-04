#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 20+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

struct BLOCK {
	int size;
	int rainbow_cnt;
	int x;
	int y;
	vector<pair<int, int>> block_pos;
};

int N, M, Answer;
int map[MAX][MAX];
int tmp[MAX][MAX];
bool visit[MAX][MAX];
bool r_visit[MAX][MAX];

void Rotate() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			tmp[i][j] = map[j][N - 1 - i];
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

bool Block_Cmp(pair<int, int> A, pair<int, int> B) {
	if (A.first <= B.first) {
		if (A.first == B.first) {
			if (A.second < B.second) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void Delete_Block(BLOCK Result) {
	vector<pair<int, int>> V = Result.block_pos;
	for (int i = 0; i < V.size(); i++) {
		int x = V[i].first;
		int y = V[i].second;
		map[x][y] = -2;
	}
	Answer += (V.size() * V.size());
}

void Gravity() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -2 || map[i][j] == -1)
				continue;

			int Color = map[i][j];
			int nx = i + 1;
			while (1) {
				if (map[nx][j] != -2)
					break;
				if (nx == N)
					break;
				nx++;
			}
			nx--;
			map[i][j] = -2;
			map[nx][j] = Color;
		}
	}
}

BLOCK BFS(int a, int b, int color) {
	memset(r_visit, false, sizeof(r_visit));
	vector<pair<int, int>> block;
	vector<pair<int, int>> except_rainbow_block;
	queue<pair<int, int>> q;
	block.push_back({ a,b });
	except_rainbow_block.push_back({ a,b });
	q.push({ a,b });
	visit[a][b] = true;
	int rainbow = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + xd[i];
			int ny = y + yd[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] == 0) {
					if (!r_visit[nx][ny]) {
						r_visit[nx][ny] = true;
						rainbow++;
						block.push_back({ nx,ny });
						q.push({ nx,ny });
					}
				}
				else if (map[nx][ny] == color) {
					if (!visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
						block.push_back({ nx,ny });
						except_rainbow_block.push_back({ nx,ny });
					}
				}
			}
		}
	}

	sort(except_rainbow_block.begin(), except_rainbow_block.end(), Block_Cmp);
	BLOCK R_Block;
	R_Block.size = block.size();
	R_Block.rainbow_cnt = rainbow;
	R_Block.x = except_rainbow_block[0].first;
	R_Block.y = except_rainbow_block[0].second;
	R_Block.block_pos = block;
	return R_Block;
}

bool Compare_Block(BLOCK A, BLOCK B) {
	if (A.size <= B.size) {
		if (A.size == B.size) {
			if (A.rainbow_cnt <= B.rainbow_cnt) {
				if (A.rainbow_cnt == B.rainbow_cnt) {
					if (A.x <= B.x) {
						if (A.x == B.x) {
							if (A.y < B.y) {
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}


BLOCK Find_Biggest_Block() {
	memset(visit, false, sizeof(visit));
	BLOCK result;
	result.size = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visit[i][j]) {
				if (map[i][j] >= 1 && map[i][j] <= M) {
					BLOCK tmp_result = BFS(i, j, map[i][j]);
					if (result.size == -1)
						result = tmp_result;
					else {
						if (Compare_Block(result, tmp_result)) {
							result = tmp_result;
						}
					}
				}
			}
		}
	}
	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		BLOCK result = Find_Biggest_Block();

		if (result.size < 2)
			break;

		Delete_Block(result);
		Gravity();
		Rotate();
		Gravity();
	}
	cout << Answer;
}