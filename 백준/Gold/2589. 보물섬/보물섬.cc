#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;
int xd[]={1,-1,0,0};
int yd[]={0,0,1,-1};

int n,m;
char map[51][51];
int Max=0;

bool check(int x, int y){
	return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int x, int y)
{
	int path = 0;

	bool visit[51][51];
	memset(visit, 0, sizeof(visit));

	queue< pair<int,int> > q;
	q.push({x, y});
	visit[x][y] = true;

	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int next_x = x + xd[j];
				int next_y = y + yd[j];

				if (!check(next_x, next_y)) continue;
				if (map[next_x][next_y] == 'W') continue;
				if (visit[next_x][next_y]) continue;

				q.push({next_x, next_y});
				visit[next_x][next_y] = true;
			}
		}
		path++;
	}
	if (Max < path - 1) Max = path - 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++){
			if (map[i][j] == 'L'){
				bfs(i, j);
			}
		}
	}
	
	cout<<Max<<endl;
	
	return 0;
}