#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1001

vector<int> g[MAX];
bool check[MAX];
int N, M, V;

void DFS(int start) {
    check[start] = true;
    cout << start<<" ";

    for (int i = 0;i < g[start].size();i++) {
        int next = g[start][i];

        if (check[next] == false) {
            DFS(next);
        }
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 0;i < g[cur].size();i++) {
            int next = g[cur][i];
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
            }
        }
    }
}

int main(void)
{   
    cin >> N >> M >> V;
    
    fill(check, check + MAX,false);
    
    for (int i = 0;i < M;i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1;i <= N;i++) {
        sort(g[i].begin(), g[i].end());
    }

    DFS(V);
    cout << endl;
    fill(check, check + MAX, false);
    BFS(V);
    return 0;
}