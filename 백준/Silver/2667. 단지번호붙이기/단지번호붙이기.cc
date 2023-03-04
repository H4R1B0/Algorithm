#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 25

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int N, cnt;
bool visit[MAX][MAX] = { false, };
string arr[MAX];
vector<int> ans;

void dfs(int i, int j) {
    visit[i][j] = true;
    cnt++;
    
    for (int k = 0;k < 4;k++) {
        int newX = i + dx[k];
        int newY = j + dy[k];

        if (0 <= newX && newX < N && 0 <= newY && newY < N) {
            if (arr[newX][newY] == '1' && !visit[newX][newY])
                dfs(newX, newY);
        }
    }
}

int main(void)
{   
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            if (arr[i][j] == '1' && !visit[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++)
        cout << ans[i] << endl;

    return 0;
}