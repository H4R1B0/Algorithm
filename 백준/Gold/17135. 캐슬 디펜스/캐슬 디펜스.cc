#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 17
#define INF 987654321

//int xd[4] = { 0,0,1,-1 };
//int yd[4] = { 1,-1,0,0 };
int xd[3] = { 0,-1,0 };
int yd[3] = {-1,0,1 };

int N, M, D, result;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
bool check[MAX][MAX];
bool visit[MAX][MAX];

void sim(int x, int y, int z)
{	
	int archer[3] = { x,y,z };
	int pos = N;
	int kill = 0;

	memset(check, false, sizeof(check));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			tmp_map[i][j] = map[i][j];
		}


	while (pos > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			memset(visit, false, sizeof(visit));

			queue<pair<int, int>> q;
			int a = pos - 1;
			int b = archer[i];
			q.push({ a, b });

			while (!q.empty())
			{
				int cx = q.front().first;
				int cy = q.front().second;
				q.pop();

				visit[cx][cy] = true;

				if (tmp_map[cx][cy] == 1)
				{
					check[cx][cy] = true;
					break;
				}

				for (int j = 0; j < 3; j++)
				{
					int nx = cx + xd[j];
					int ny = cy + yd[j];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M)
						if ((abs(pos - nx) + abs(archer[i] - ny) <= D))
							if (!visit[nx][ny])
								q.push({ nx, ny });

				}
			}

		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (check[i][j])
					tmp_map[i][j] = 0;


		pos--;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (check[i][j])
				kill++;

	result = max(result, kill);
}

int main(void)
{
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			for (int k = j + 1; k < M; k++)
				sim(i, j, k);

	cout << result << endl;
}