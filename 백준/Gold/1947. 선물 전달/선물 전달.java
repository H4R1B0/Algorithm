import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int N;
    static final int MOD = 1000000000;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        long[] dp = new long[N + 2];

        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= N; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
            dp[i] %= MOD;
        }
        System.out.println(dp[N]);
    }
}