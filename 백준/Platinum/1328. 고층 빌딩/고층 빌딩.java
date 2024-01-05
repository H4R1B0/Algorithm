import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        long[][][] dp = new long[N + 1][N + 1][N + 1];
        dp[1][1][1] = 1;
        if (N > 1) {
            dp[2][2][1] = dp[2][1][2] = 1;
        }
        for (int n = 3; n <= N; n++) {
            for (int l = 1; l <= L; l++) {
                for (int r = 1; r <= R; r++) {
                    dp[n][l][r] += dp[n - 1][l - 1][r] % MOD;
                    dp[n][l][r] += dp[n - 1][l][r - 1] % MOD;
                    dp[n][l][r] += (dp[n - 1][l][r] * (n - 2)) % MOD;
                    dp[n][l][r] %= MOD;
                }
            }
        }
        System.out.println(dp[N][L][R]);
    }
}