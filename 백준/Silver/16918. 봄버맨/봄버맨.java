import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int[][] board;
    static int R, C, N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        board = new int[R][C];
        for (int i = 0; i < R; i++) {
            char[] tmp = br.readLine().toCharArray();
            for (int j = 0; j < C; j++) {
                if (tmp[j] == 'O') {
                    board[i][j] = 1;
                }
            }
        }
        solve();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 0)
                    System.out.print('.');
                else
                    System.out.print('O');
            }
            System.out.println();
        }
    }

    static void solve() {
        for (int time = 0; time < N - 1; time++) {
            if (time % 2 == 0) {
                fillBomb();
            } else {
//                fillBomb();
                boom();
            }
        }
    }

    static void fillBomb() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j]++;
            }
        }
    }

    static void boom() {
        Queue<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j]++;
                if (board[i][j] >= 3) {
                    q.add(new int[]{i, j});
                }
            }
        }
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            board[cur[0]][cur[1]] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + xd[i];
                int ny = cur[1] + yd[i];
                if (isInRange(nx, ny)) {
                    board[nx][ny] = 0;
                }
            }
        }
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < R && y >= 0 && y < C;
    }
}