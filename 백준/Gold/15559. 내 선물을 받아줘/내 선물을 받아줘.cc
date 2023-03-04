#include <bits/stdc++.h>
using namespace std;
int n, m;
int par[1000001];
char a[1001][1001];
#define loop(i,n) for(int i=1;i<=n;i++)
 
int find(int x) {
    return (par[x] < 0) ? x : par[x] = find(par[x]);
}
 
// 왼쪽이 자식이 되게 합친다. 
void uni(int x, int y) {
    x = find(x); y = find(y);
    if (x != y) par[y] = x;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    loop(i, n)loop(j, m)  cin >> a[i][j];
    memset(par, -1, sizeof(par));
    loop(i, n)loop(j, m) {
        // 현재 방향이 다음 방향의 자식이 되게 합친다. 
        // (i, j)는 m*(i-1)+j 로 표현된다. 
        if (a[i][j] == 'N') uni(m * (i - 2) + j, m * (i - 1) + j);
        if (a[i][j] == 'S') uni(m * i + j, m * (i - 1) + j);
        if (a[i][j] == 'E') uni(m * (i - 1) + j + 1, m * (i - 1) + j);
        if (a[i][j] == 'W') uni(m * (i - 1) + j - 1, m * (i - 1) + j);
    }
    int ans = 0;
    // 사이클 개수 = 부모가 -1인 점의 개수 
    loop(i, n * m) ans += (par[i] < 0);
    cout << ans;
}
