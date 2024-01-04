import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final int MOD = 1000000000;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][][] dp = new int[N + 1][10][1 << 10];
        for (int i = 1; i < 10; i++) {
            dp[1][i][1 << i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                for (int bit = 0; bit < (1 << 10); bit++) {
                    if (j >= 1) {
                        dp[i][j][bit | (1 << j)] += dp[i - 1][j - 1][bit];
                    }
                    dp[i][j][bit | (1 << j)] %= MOD;
                    if (j <= 8) {
                        dp[i][j][bit | (1 << j)] += dp[i - 1][j + 1][bit];
                    }
                    dp[i][j][bit | (1 << j)] %= MOD;
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < 10; i++) {
            answer += dp[N][i][(1 << 10) - 1];
            answer %= MOD;
        }
        System.out.println(answer);
    }
}