import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int[][] board;
    static boolean[][] visit;
    static int N, M, answer = 0, zeroCnt;
    static List<Pos> virusPositions = new ArrayList<>();
    static Queue<Pos> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        N = Integer.parseInt(tmp[0]);
        M = Integer.parseInt(tmp[1]);
        board = new int[N][M];
        visit = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 2)
                    virusPositions.add(new Pos(i, j));
                if (board[i][j] == 0)
                    zeroCnt++;
            }
        }
        makeWall(0);
        System.out.println(answer);
    }

    static void makeWall(int cnt) {
        if (cnt == 3) {
            spread();
            return;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1;
                    makeWall(cnt + 1);
                    board[i][j] = 0;
                }
            }
        }
    }

    static void spread() {
        q.clear();
        int cnt = 0;
        for (int i = 0; i < N; i++)
            Arrays.fill(visit[i], false);
        for (Pos virusPosition : virusPositions) {
            q.add(virusPosition);
            visit[virusPosition.x][virusPosition.y] = true;
        }
        while (!q.isEmpty()) {
            Pos cur = q.poll();
            int x = cur.x;
            int y = cur.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];

                if (isInRange(nx, ny)) {
                    if (!visit[nx][ny] && board[nx][ny] == 0) {
                        visit[nx][ny] = true;
                        q.add(new Pos(nx, ny));
                        cnt++;
                    }
                }
            }
        }
        answer = Math.max(answer, zeroCnt - cnt - 3);
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}