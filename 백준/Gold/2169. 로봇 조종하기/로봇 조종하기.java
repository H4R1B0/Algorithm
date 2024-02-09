import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] xd = {0, 0, 1};
    static int[] yd = {-1, 1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[][] board = new int[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        int[][] dp = new int[N][M];
        dp[0][0] = board[0][0];
        for (int i = 1; i < M; i++) {
            dp[0][i] = board[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < N; i++) {
            int[] tmp1 = new int[M];
            int[] tmp2 = new int[M];

            tmp1[0] = dp[i - 1][0] + board[i][0];
            for (int j = 1; j < M; j++) {
                tmp1[j] = Math.max(tmp1[j - 1], dp[i - 1][j]) + board[i][j];
            }

            tmp2[M - 1] = dp[i - 1][M - 1] + board[i][M - 1];
            for (int j = M - 2; j >= 0; j--) {
                tmp2[j] = Math.max(dp[i - 1][j], tmp2[j + 1]) + board[i][j];
            }
            for (int j = 0; j < M; j++) {
                dp[i][j] = Math.max(tmp1[j], tmp2[j]);
            }
        }
        System.out.println(dp[N - 1][M - 1]);
    }
}