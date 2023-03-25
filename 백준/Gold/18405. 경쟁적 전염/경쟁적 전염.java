import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N, K;
    static int S, X, Y;
    static int[][] board;
    static List<int[]> viruses = new ArrayList<int[]>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        board = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] > 0) {
                    viruses.add(new int[]{i, j});
                }
            }
        }
        viruses.sort((o1, o2) -> {
            return board[o1[0]][o1[1]] - board[o2[0]][o2[1]];
        });
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        System.out.println(getAnswer());
    }

    static int getAnswer() {
        Queue<int[]> q = new LinkedList<>(viruses);

        while (S-- > 0) {
            int qSize = q.size();
            while (qSize-- > 0) {
                int[] cur = q.poll();
                int x = cur[0];
                int y = cur[1];

                for (int i = 0; i < 4; i++) {
                    int nx = x + xd[i];
                    int ny = y + yd[i];
                    if (isInRange(nx, ny)) {
                        if (board[nx][ny] == 0) {
                            board[nx][ny] = board[x][y];
                            q.add(new int[]{nx, ny});
                        }
                    }
                }
            }
        }
        return board[X - 1][Y - 1];
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}