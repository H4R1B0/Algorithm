#include <iostream>
#include <vector>
#include <queue>

#define MAX 32002

using namespace std;

int N, M;
int Entry[MAX];
vector<int> Node[MAX];

void Solution() {
    priority_queue<int> Q;
    
    for (int i = 1;i <= N;i++) {
        if (Entry[i] == 0)
            Q.push(-i);
    }

    while (!Q.empty()) {
        int Cur = -Q.top();
        Q.pop();

        cout << Cur << " ";
        for (int i = 0;i < Node[Cur].size();i++) {
            int Next = Node[Cur][i];
            Entry[Next]--;

            if (Entry[Next] == 0)
                Q.push(-Next);
        }
    }
    cout << endl;
}

int main(void)
{   
    cin >> N >> M;
    for (int i = 0;i < M;i++) {
        int a, b;
        cin >> a >> b;
        Node[a].push_back(b);
        Entry[b]++;        
    }
    Solution();
}