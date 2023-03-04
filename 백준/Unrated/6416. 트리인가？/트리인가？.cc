#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <cmath>
#include <tuple>
#include <map>
#include <set>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 987654321
//#define INF 9223372036854775800

//int xd[] = { 0,0,1,-1 };
//int yd[] = { 1,-1,0,0 };

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int testCase = 1;

int bfs(map<int, vector<int>>& treeMap) {
    map <int, int> ckMap;

    for (auto t : treeMap)
        for (auto el : t.second)
            ckMap[el] = 1;

    int root = 0;
    for (auto t : treeMap)
        if (!ckMap[t.first])
            root = t.first;
    ckMap.clear();
    ckMap[root] = 1;
    queue <int> q;
    q.push(root);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < treeMap[x].size(); i++) {
            int nx = treeMap[x][i];
            if (ckMap[nx] == 1)
                return 0;
            ckMap[nx] = 1;
            q.push(nx);
        }
    }

    for (auto t : treeMap) {
        for (auto el : t.second) {
            if (!ckMap[el] || !ckMap[t.first])
                return 0;
        }
    }
    return 1;
}

int main() {
    while (1) {
        int edgeCnt = 0;
        map<int, vector<int>> treeMap;
        set <int> vertex;
        int u, v;
        while (1) {
            cin >> u >> v;
            edgeCnt++;
            vertex.insert(u);
            vertex.insert(v);
            if (u == -1 && v == -1)
                return 0;
            if (u == 0 && v == 0)
                break;
            treeMap[u].push_back(v);
        }
        if (u && v && vertex.size() != edgeCnt + 1)
            cout << "Case " << testCase << " is not a tree." << endl;
        else {
            if (bfs(treeMap))
                cout << "Case " << testCase << " is a tree." << endl;
            else
                cout << "Case " << testCase << " is not a tree." << endl;
        }
        testCase++;
    }
}