import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] dp;
    static int[] sum;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        sum = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            int a = Integer.parseInt(br.readLine());
            sum[i] = sum[i - 1] + a;
        }
        dp = new int[N + 1][M + 1];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE);
        }
        int answer = dfs(N, M);
        System.out.println(answer);
    }

    private static int dfs(int idx, int m) {
        if (m == 0)
            return 0;

        if (idx < 0)
            return -32768 * 100;

        if (dp[idx][m] != Integer.MIN_VALUE)
            return dp[idx][m];

        dp[idx][m] = dfs(idx - 1, m);
        for (int i = idx; i > 0; i--) {
            dp[idx][m] = Math.max(dp[idx][m], (sum[idx] - sum[i - 1]) + dfs(i - 2, m - 1));
        }

        return dp[idx][m];
    }
}