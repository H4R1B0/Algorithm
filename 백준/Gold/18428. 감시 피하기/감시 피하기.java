import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N;
    static char[][] board;
    static boolean isFind = false;
    static int studentCount = 0;
    static List<int[]> teachers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new char[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = st.nextToken().charAt(0);
                if (board[i][j] == 'T') {
                    teachers.add(new int[]{i, j});
                }
            }
        }
        dfs(0);
        System.out.println(isFind ? "YES" : "NO");
    }

    static void dfs(int cnt) {
        if (cnt == 3) {
            //답은 찾은 경우
            if (isFind)
                return;
            isFind = isAnswer();
            return;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'X') {
                    board[i][j] = 'O';
                    dfs(cnt + 1);
                    board[i][j] = 'X';
                }
            }
        }
    }

    static boolean isAnswer() {
        int cnt = 0;
        boolean[][] check = new boolean[N][N];
        for (int[] teacher : teachers) {
            int x = teacher[0];
            int y = teacher[1];

            for (int dir = 0; dir < 4; dir++) {
                int nx = x, ny = y;
                while (true) {
                    nx += xd[dir];
                    ny += yd[dir];
                    if(!isInRange(nx,ny))
                        break;
                    if(board[nx][ny] == 'O')
                        break;
                    if(check[nx][ny])
                        continue;
                    if(board[nx][ny] == 'S') {
                        check[nx][ny] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt == 0;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}