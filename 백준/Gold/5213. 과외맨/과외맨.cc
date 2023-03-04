#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

#define endl "\n"
#define MAX 550
using namespace std;

typedef struct
{
    int Left;
    int Right;
    int Num;
}TILE;

int N, Max_Tile, Last_Tile;
TILE MAP[MAX][MAX];
bool Visit[MAX][MAX];
int Path[MAX * MAX];

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Initialize()
{
    Max_Tile = 0;
    memset(MAP, -1, sizeof(MAP));
}

void Input()
{
    cin >> N;
    int Num = 1;
    int EvenOrOdd;

    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1) EvenOrOdd = 1; // 홀수 행에 대해서는 True 값을
        else EvenOrOdd = 0;              // 짝수 행에 대해서는 False 값을

        for (int j = 1; j <= N - 1 + EvenOrOdd; j++)
        {
            cin >> MAP[i][j].Left >> MAP[i][j].Right;
            MAP[i][j].Num = Num;
            Num++;
        }
    }
}

void BFS()
{
    queue<pair<pair<int, int>, int > > Q;
    Q.push(make_pair(make_pair(1, 1), 1));
    Visit[1][1] = true;
    Path[1] = 0;

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int n = Q.front().second;
        Q.pop();

		int EvenOrOdd = x % 2;
        Max_Tile = Bigger(n, Max_Tile);

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nn = MAP[nx][ny].Num;

            if (MAP[nx][ny].Left == -1 || MAP[nx][ny].Right == -1)
                continue;
            if (Visit[nx][ny])
                continue;

            if (EvenOrOdd == 1) // 홀수 행일 때
            {
                if (i == 2 || i == 4) continue;
                else if (i == 0 || i == 6 || i == 7)
                {
                    if (MAP[nx][ny].Right == MAP[x][y].Left) {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), nn));
                        Path[nn] = n;
                    }
                }
                else if (i == 1 || i == 3 || i == 5) {
                    if (MAP[nx][ny].Left == MAP[x][y].Right) {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), nn));
                        Path[nn] = n;
                    }
                }
            }
            else
            {
                if (i == 0 || i == 6)
                    continue;
                else if (i == 1 || i == 5 || i == 7)
                {
                    if (MAP[nx][ny].Right == MAP[x][y].Left) {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), nn));
                        Path[nn] = n;
                    }
                }
                else if (i == 2 || i == 3 || i == 4)
                {
                    if (MAP[nx][ny].Left == MAP[x][y].Right) {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), nn));
                        Path[nn] = n;
                    }
                }
            }
        }
    }
}

void Find_Result_Path()
{
    vector<int> V;

    int Tmp = Max_Tile;
    V.push_back(Tmp);
    while (Path[Tmp] != 0)
    {
        V.push_back(Path[Tmp]);
        Tmp = Path[Tmp];
    }
    cout << V.size() << endl;
    for (int i = V.size() - 1; i >= 0; i--)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}

void Solution()
{
    BFS();
    Find_Result_Path();
}

void Solve()
{
    Initialize();
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
