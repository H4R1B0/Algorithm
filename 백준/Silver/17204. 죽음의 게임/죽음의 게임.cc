#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"
#define MAX 150+1
#define INF 987654321
using namespace std;

int xd[] = { 0,0,1,-1,1,1,-1,-1 };
int yd[] = { 1,-1,0,0,1,-1,1,-1 };

int N, K;
bool visit[MAX];

int main(void) {
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0;i < N;i++) {
        cin >> v[i];
    }

    vector<int> count(MAX);

    int next = v[0];
    for (int i = 1;;i++) {
        if (count[next] == 1) {
            cout << -1;
            break;
        }

        if (next == K) {
            cout << i;
            break;
        }

        count[next]++;
        next = v[next];
    }
}
