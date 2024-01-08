import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N;
    static final int MOD = 987654321;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        long[] dp = new long[N + 2];

        dp[0] = 1;
        dp[2] = 1;
        for (int i = 4; i <= N; i += 2) {
            for (int j = 2; j <= i; j += 2) {
                dp[i] += dp[j - 2] * dp[i - j];
                dp[i] %= MOD;
            }
        }
        System.out.println(dp[N]);
    }
}