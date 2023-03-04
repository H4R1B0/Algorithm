import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int R, C, T;
    static int[][] board;
    static Pos[] machines = new Pos[2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        board = new int[R][C];
        int idx = 0;
        for (int i = 0; i < R; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < C; j++) {
                if (board[i][j] == -1)
                    machines[idx++] = new Pos(i, j);
            }
        }

        System.out.println(getAnswer());
//        print();
    }

    static void print() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    static int getAnswer() {
        while (T-- > 0) {
            spread();
            run();
        }
        int answer = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] != 0)
                    answer += board[i][j];
            }
        }
        return answer+2;
    }

    private static void run() {
        //위
        for (int i = machines[0].x - 2; i >= 0; i--) {
            board[i + 1][0] = board[i][0];
        }
        for (int i = 1; i < C; i++) {
            board[0][i - 1] = board[0][i];
        }
        for (int i = 1; i <= machines[0].x; i++) {
            board[i - 1][C - 1] = board[i][C - 1];
        }
        for (int i = C - 2; i >= 1; i--) {
            board[machines[0].x][i + 1] = board[machines[0].x][i];
        }
        board[machines[0].x][1] = 0;

        //아래
        for (int i = machines[1].x + 2; i < R; i++) {
            board[i - 1][0] = board[i][0];
        }
        for (int i = 1; i < C; i++) {
            board[R - 1][i - 1] = board[R - 1][i];
        }
        for (int i = R - 2; i >= machines[1].x; i--) {
            board[i + 1][C - 1] = board[i][C - 1];
        }
        for (int i = C - 2; i >= 1; i--) {
            board[machines[1].x][i + 1] = board[machines[1].x][i];
        }
        board[machines[1].x][1] = 0;

    }

    private static void spread() {
        int[][] tmp = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] != 0) {
                    int sum = 0;
                    int num = board[i][j] / 5;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + xd[dir];
                        int ny = j + yd[dir];
                        if (isInRange(nx, ny) && board[nx][ny] != -1) {
                            tmp[nx][ny] += num;
                            sum += num;
                        }
                    }
                    tmp[i][j] += (board[i][j] - sum);
                }
            }
        }

        for (int i = 0; i < R; i++) {
            board[i] = tmp[i].clone();
        }
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < R && y >= 0 && y < C;
    }

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}