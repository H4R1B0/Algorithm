#include <iostream>
using namespace std;

int map[101][101];
int visit[101][101];
int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int chzcnt;
int lastcnt;

void init(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			visit[i][j] = 0;
		}
	}
}

void dfs(int x, int y){
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++){
		if (map[x + dx[i]][y + dy[i]] == 1 && !visit[x + dx[i]][y + dy[i]]){
			map[x + dx[i]][y + dy[i]] = 0;
			visit[x + dx[i]][y + dy[i]] = 1;
			chzcnt--;
			lastcnt++;
		}
		else if (map[x + dx[i]][y + dy[i]] == 0 && !visit[x + dx[i]][y + dy[i]]){
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			map[i][j] = -1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> map[i][j];
			if (map[i][j] == 1)
				chzcnt++;
		}

	int k = 0;
	while (chzcnt){
		k++;
		lastcnt = 0;
		dfs(1, 1);
		init();
	}
	cout<<k<<endl<<lastcnt<<endl;

}