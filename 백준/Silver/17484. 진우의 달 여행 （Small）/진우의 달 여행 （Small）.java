import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] board = new int[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        int[][][] dp = new int[N][M][3];
        for (int i = 0; i < M; i++) {
            dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = board[0][i];
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = 1000;
                    if ((j == 0 && k == 2) || (j == M - 1 && k == 0)) {
                        continue;
                    }
                    for (int l = 0; l < 3; l++) {
                        if (k == l) {
                            continue;
                        }
                        dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j - k + 1][l] + board[i][j]);
                    }
                }
            }
        }
        int answer = 1000;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 3; j++) {
                answer = Math.min(answer, dp[N - 1][i][j]);
            }
        }
        System.out.println(answer);
    }
}