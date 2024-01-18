import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int fac[] = new int[10];
        fac[0] = 1;
        for (int i = 1; i < 10; i++) {
            fac[i] = fac[i - 1] * i;
        }

        int[] dp = new int[N + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = i;
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = Math.min(dp[i], dp[j] + dp[i - j]);
            }
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    dp[i] = Math.min(dp[i], dp[j] + dp[i / j]);
                }
            }
            for (int j = 2; j < 10; j++) {
                if (i == fac[j]) {
                    dp[i] = Math.min(dp[i], dp[j]);
                }
            }
        }
        System.out.println(dp[N]);
    }
}