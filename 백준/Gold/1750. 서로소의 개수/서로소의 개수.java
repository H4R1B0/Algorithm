import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int MOD = 10000003;
    static int N;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N][100001];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            dp[i][arr[i]] = 1;
        }

        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= 100000; j++) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;

                int a = gcd(arr[i], j);
                dp[i][a] += dp[i - 1][j];
                dp[i][a] %= MOD;
            }
        }
        System.out.println(dp[N-1][1]);
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}