import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N, M;
    static int time, result;
    static int[][] board;
    static boolean[][] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            visit = new boolean[N][M];
            if (bfs())
                break;
        }

        System.out.println(time-1);
        System.out.println(result);
    }

    private static boolean bfs() {
        int cnt = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visit[0][0] = true;
        time++;
        while (!q.isEmpty()) {
            int[] cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + xd[i];
                int ny = cur[1] + yd[i];

                if (isInRange(nx, ny) && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    if (board[nx][ny] == 0) {
                        q.add(new int[]{nx, ny});
                    } else {
                        cnt++;
                        board[nx][ny] = 0;
                    }
                }
            }
        }

        if (cnt == 0) {
            return true;
        }
        result = cnt;
        return false;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}