import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    static int[] xd = {0, 1, 0, -1};
    static int[] yd = {1, 0, -1, 0};
    static int N, M, K;
    static int[][] board;
    static List<Cmd> kinds = new ArrayList<>();
    static List<Integer> cmds = new ArrayList<>();
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        N = Integer.parseInt(tmp[0]);
        M = Integer.parseInt(tmp[1]);
        K = Integer.parseInt(tmp[2]);

        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        for (int i = 0; i < K; i++) {
            tmp = br.readLine().split(" ");
            int r = Integer.parseInt(tmp[0]);
            int c = Integer.parseInt(tmp[1]);
            int s = Integer.parseInt(tmp[2]);
            kinds.add(new Cmd(r, c, s));
        }

        dfs(0);
        System.out.println(answer);
    }

    static void dfs(int cnt) {
        if (cnt == K) {
            getAnswer();
            return;
        }

        for (int i = 0; i < K; i++) {
            if (!cmds.contains(i)) {
                cmds.add(i);
                dfs(cnt + 1);
                cmds.remove(cmds.size() - 1);
            }
        }
    }

    static void getAnswer() {
        int[][] tmpBoard = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmpBoard[i][j] = board[i][j];
            }
        }

        for (int cmd : cmds) {
            int r = kinds.get(cmd).r;
            int c = kinds.get(cmd).c;
            int s = kinds.get(cmd).s;

            for (int i = 0; i < s; i++) {
                int[] top = {r - s + i - 1, c - s + i - 1};
                int[] bottom = {r + s - i - 1, c + s - i - 1};
                int nx = top[0], ny = top[1];
                int tmp = tmpBoard[nx][ny];

                for (int dir = 0; dir < 4; dir++) {
                    while (true) {
                        nx += xd[dir];
                        ny += yd[dir];
                        if (!isInRange(nx, ny, top, bottom)) {
                            nx -= xd[dir];
                            ny -= yd[dir];
                            break;
                        }
                        int tmp2 = tmp;
                        tmp = tmpBoard[nx][ny];
                        tmpBoard[nx][ny] = tmp2;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += tmpBoard[i][j];
            }
            answer = Math.min(answer, sum);
        }
    }

    static boolean isInRange(int x, int y, int[] top, int[] bottom) {
        return x >= top[0] && x <= bottom[0] && y >= top[1] && y <= bottom[1];
    }

    static class Cmd {
        int r, c, s;

        public Cmd(int r, int c, int s) {
            this.r = r;
            this.c = c;
            this.s = s;
        }
    }
}