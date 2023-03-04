#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 101


int N,M, cnt;
bool visit[MAX] = { false, };

vector<int> node[MAX];

void dfs(int start) {
    visit[start] = true;
    cnt++;
    
    for (int i = 0;i < node[start].size();i++) {
        int next = node[start][i];

        if (visit[next] == false) {
            dfs(next);
        }
    }
}

int main(void)
{   
    cin >> N;
    cin >> M;        

    for (int i = 0;i < M;i++) {
        int a, b;
        cin >> a >> b;

        node[a].push_back(b);
        node[b].push_back(a);

    }
    dfs(1);
    cout << cnt-1;

    return 0;
}