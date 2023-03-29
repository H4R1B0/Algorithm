import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int[] hxd = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] hyd = {1, 2, 2, 1, -1, -2, -2, -1};
    static int K, W, H;
    static int[][] board;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        K = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        board = new int[H][W];
        for (int i = 0; i < H; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < W; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(getAnswer());
    }

    static int getAnswer() {
        boolean[][][] visit = new boolean[H][W][K + 1];
        //x,y,cnt
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0, K, 0});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int k = cur[2];
            int cnt = cur[3];

            if (x == H - 1 && y == W - 1)
                return cnt;

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];
                if (isInRange(nx, ny) && !visit[nx][ny][k] && board[nx][ny] != 1) {
                    visit[nx][ny][k] = true;
                    q.add(new int[]{nx, ny, k, cnt + 1});
                }
            }
            if (k > 0) {
                for (int i = 0; i < 8; i++) {
                    int nx = x + hxd[i];
                    int ny = y + hyd[i];
                    if (isInRange(nx, ny) && !visit[nx][ny][k - 1] && board[nx][ny] != 1) {
                        visit[nx][ny][k - 1] = true;
                        q.add(new int[]{nx, ny, k - 1, cnt + 1});
                    }
                }
            }
        }
        return -1;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    }
}
